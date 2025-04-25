#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n, m, q);
  VEC(P, p, n);
  vector<circle<ll>> c(m);
  FOR(i, m) {
    LL(R);
    PO(O);
    c[i] = {O, R};
  }
  meion sq = [](ll x) { iroha x * x; };
  meion dis = [&](P x, P y) -> ll { iroha sq(x.x - y.x) + sq(x.y - y.y); };
  meion inout = [&](ll a, ll b) { iroha dis(p[a], c[b].O) <= c[b].r* c[b].r; };
  meion check = [&](ll a, ll b, ll c) { iroha inout(a, c) ^ inout(b, c); };
  FOR(q) {
    LL(a, b);
    --a, --b;
    ll ans = 0;
    FOR(i, m) ans += check(a, b, i);
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"