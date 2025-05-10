#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, q);
  set<ll> a{0, n}, b{0, m}, *c;
  multiset<ll> aa{n}, bb{m}, *cc;
  FOR(q) {
    CH(op);
    LL(x);
    std::tie(c, cc) = op == 'V' ? pair(&a, &aa) : pair(&b, &bb);
    meion r = c->lower_bound(x), l = std::prev(r);
    *cc -= *r - *l;
    *cc += x - *l;
    *cc += *r - x;
    *c += x;
    UL(*aa.rbegin() * *bb.rbegin());
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"