#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/ptable.hpp"

void f(ll &a, ll &b) {
  ll g = gcd(a, b);
  a /= g, b /= g;
}
vc<ll> ge(ll a) {
  static vc<ll> rs;
  rs.clear();
  for (int e : ptable(1'000'000)) {
    if (a % e == 0) {
      rs.ep(e);
      do {
        a /= e;
      } while (a % e == 0);
    }
    if (e > a) break;
  }
  if (a != 1) rs.ep(a);
  return rs;
}
void Yorisou() {
  LL(a, b);
  INT(Q);
  VEC(ll, q, Q);
  if (a == b) {
    FOR(Q) print(1, 1);
    return;
  }
  if (abs(a - b) == 1) {
    for (ll d : q) print(a + d, b + d);
    return;
  }
  ll c = 0, mx = QMAX(q);
  int i = 0;
  vc<PLL> rs(Q);
  vc<int> I = argsort(q);
  vc<ll> es;
  while (c < mx) {
    if (abs(a - b) == 1) break;
    if (es.empty()) es = ge(abs(a - b));
    ll go = inf<ll>;
    for (ll e : es) if (a % e) {
      ll d = a / e + 1;
      chmin(go, d * e);
    }
    ll d = go - a;
    while (i < Q and q[I[i]] <= c + d) {
      int id = I[i];
      ll aa = a + q[id] - c, bb = b + q[id] - c;
      f(aa, bb);
      rs[id] = {aa, bb};
      ++i;
    }
    a += d, b += d, c += d;
    f(a, b);
  }
  FOR(k, i, Q) {
    int id = I[k];
    ll g = q[id], aa = a + g - c, bb = b + g - c;
    rs[id] = {aa, bb};
  }
  for (var [a, b] : rs) print(a, b);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}