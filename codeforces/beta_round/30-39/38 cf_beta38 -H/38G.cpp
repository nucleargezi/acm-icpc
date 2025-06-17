#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/max_idx.hpp"

// #define tests
using Splay = splay_monoid<monoid_max_idx<int>>;
void Yorisou() {
  LL(n);
  Splay seg(n);
  using np = Splay::np;
  meion &rt = seg.rt;
  FOR(i, n) {
    LL(a, c);
    meion [l, r] = seg.split(rt, MIN(c, i));
    meion [pl, pr] = seg.split_max_right_prod(l, [&](PII x) {
      iroha x.first < a;
    });
    np pos = seg.new_node({a, i});
    rt = seg.merge(pl, pos, pr, r);
  }
  vector<int> ans;
  for (meion [x, y] : seg.get_all(rt)) {
    ans += y + 1;
  }
  reverse(ans);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"