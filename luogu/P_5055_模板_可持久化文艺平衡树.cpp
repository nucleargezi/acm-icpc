#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/treap/treap_commute_monoid.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<ll>;
using treap = treap_commute_monoid<mono, true>;
using np = treap::np;
void Yorisou() {
  LL(q);
  ll ans = 0;
  treap seg(q * 70);
  vector<np> rt(q + 1, nullptr);
  for (int i = 1; i < q + 1; ++i) {
    LL(v, op);
    if (op == 1) {
      LL(p, x);
      p ^= ans, x ^= ans;
      rt[i] = seg.ins(rt[v], p, x);
    } else if (op == 2) {
      LL(p);
      p ^= ans;
      --p;
      rt[i] = seg.del(rt[v], p);
    } else if (op == 3) {
      LL(l, r);
      l ^= ans, r ^= ans;
      if (l > r) swap(l, r);
      --l;
      rt[i] = seg.reverse(rt[v], l, r);
    } else {
      LL(l, r);
      l ^= ans, r ^= ans;
      if (l > r) swap(l, r);
      --l;
      rt[i] = rt[v];
      UL(ans = seg.prod(rt[v], l, r));
    }
  }
}
#include "YRS/Z_H/main.hpp"