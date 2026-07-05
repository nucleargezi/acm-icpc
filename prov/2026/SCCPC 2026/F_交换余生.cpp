#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  if (QMAX(a) == QMIN(a)) return NO();
  if (N == 2) return YES();
  ll g = 0;
  for (ll x : a) g = gcd(g, x);
  for (ll &x : a) x /= g;
  vc<ll> es;
  FOR(i, min(N, 2)) {
    for (var [e, p] : factor(a[i])) es.ep(e);
  }
  unique(es);

  Z ck = [&](ll p) -> bool {
    vc<ll> st;
    for (ll x : a) if (x % p != 0) st.ep(x);
    if (si(st) <= 1) return 1;
    vc<ll> ee;
    FOR(i, min<ll>(2, si(st))) {
      for (var [e, p] : factor(st[i])) ee.ep(e);
    }
    unique(ee);
    for (ll e : ee) {
      int c = 0;
      for (ll x : st) c += x % e == 0;
      if (c >= si(st) - 1) return 1;
    }
    return 0;
  };
  for (ll p : es) if (ck(p)) return YES();
  NO();
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}