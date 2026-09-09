#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr ll L = 1'000'000'000'000'000'000ll;

void Yorisou() {
  LL(N, K);
  vc<ll> a, b;
  ll z = 0;
  FOR(N) {
    LL(x);
    if (x < 0) a.ep(-x);
    else if (x == 0) ++z;
    else b.ep(x);
  }
  sort(a);
  sort(b);
  Z ck = [&](ll x) -> bool {
    ll c = 0;
    if (x == 0) {
      c = si(a) * si(b) + z * (si(a) + si(b)) + z * (z - 1) / 2;
    } else if (x < 0) {
      for (ll e : a) c += si(b) - lb(b, ceil(-x, e));
    } else {
      c += z * (si(a) + si(b));
      c += si(a) * si(b);
      c += z * (z - 1) / 2;
      FOR(i, si(a)) {
        ll e = a[i], k = ub(a, x / e);
        chmin(k, i);
        c += k;
      }
      FOR(i, si(b)) {
        ll e = b[i], k = ub(b, x / e);
        chmin(k, i);
        c += k;
      }
    }
    return c >= K;
  };

  print(bina(ck, L, -L - 1));
}

int main() { Yorisou(); }