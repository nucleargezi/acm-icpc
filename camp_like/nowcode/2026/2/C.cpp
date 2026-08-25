#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

PLL slv(ll ca, ll cb, ll a, ll b) {
  ll c = min(a, b), d = a - b;
  Z ck = [&](ll mx) -> bool {
    if (mx == 0) return 0;
    ll t;
    if (cb == 0) {
      if (ca > mx) return 0;
      t = ca;
    } else {
      if (ca > mx * (cb + 1)) return 0;
      t = max(0ll, ca - mx * cb);
    }
    if (c == 0) return d <= 0 or t + d <= mx;
    if (d <= 0) return 1;
    if (d == 1) return mx >= 2 or t == 0;
    if (mx < 2) return 0;
    if (mx >= 3) return 1;
    return c >= 2 or t <= 1;
  };
  ll l = bina(ck, ca + a, 0), r;
  if (c == 0) {
    r = ca + max(d, 0ll);
  } else {
    r = ca + 1;
    chmax(r, 1 + max(d, 0ll));
    if (c >= 2) chmax(r, 2);
  }
  return {l, r};
}

PII sl(int K, int a, int b, int aa, int bb) {
  int r = aa - a;
  int l = bina([&](ll mx) -> bool {
    return mx * (bb - b + 1) + a >= aa;
  }, r, -1);
  return {l, r};
}

void Yorisou() {
  LL(K, a, b, aa, bb);
  if (a == aa) return print(0, 0);
  if (b == bb) return print(aa - a, aa - a);

  if (aa <= K - 1 and bb <= K - 1) return print(sl(K, a, b, aa, bb));

  if (aa == K and bb < K - 1) {
    int r = aa - a;
    int l = bina([&](ll mx) -> bool {
      return mx * (bb - b + 1) + a >= aa;
    }, r, -1);
    return print(l, r);
  }
  if (bb == K and aa < K - 1) {
    int r = aa - a;
    int l = bina([&](ll mx) -> bool {
      return mx * (bb - b) + a >= aa;
    }, r, -1);
    return print(l, r);
  }
  ll ca, cb;
  if (a < K and b < K) {
    ca = K - 1 - a, cb = K - 1 - b;
    aa -= K - 1, bb -= K - 1;
  } else if (a == b + 1) {
    ca = 0, cb = 1, aa -= a, bb -= b + 1;
  } else if (b == a + 1) {
    ca = 1, cb = 0;
    aa -= a + 1, bb -= b;
  } else {
    ca = cb = 0;
    aa -= a, bb -= b;
  }
  print(slv(ca, cb, aa, bb));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}