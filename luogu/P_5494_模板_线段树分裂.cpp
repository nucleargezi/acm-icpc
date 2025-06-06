#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg_bin.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<ll>;
using Seg = dynamic_seg_with_bin<mono>;
using np = Seg::np;
void Yorisou() {
  LL(n, q);
  VEC(ll, dat, n);
  Seg seg(6'000'000, 0, n);
  np tcl = seg.new_root();
  FOR(i, n) seg.set(tcl, i, 0);
  vector<np> t(q + 1);
  int tot = 0;
  t[tot++] = seg.new_node(dat);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, l, r);
      --p, --l; 
      t[tot++] = seg.split(t[p], l, r);
    } else if (op == 1) {
      LL(to, frm);
      --to, --frm;
      seg.merge<false>(t[to], t[frm]);
    } else if (op == 2) {
      LL(p, x, q);
      --p, --q;
      seg.apply(t[p], q, x);
    } else if (op == 3) {
      LL(p, l, r);
      --p, --l;
      UL(seg.prod(t[p], l, r));
    } else {
      LL(p, k);
      --p;
      if (seg.prod(t[p], 0, n) < k) {
        UL(-1);
      } else {
        UL(seg.max_right(t[p], [&](ll s) -> bool {
          iroha s < k;
        }, 0) + 1);
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"