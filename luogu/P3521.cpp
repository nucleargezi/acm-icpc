#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/dynamic_seg.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<int>;
using Seg = dynamic_seg<mono>;
using np = Seg::np;
void Yorisou() {
  INT(N);
  ll ans = 0;
  Seg seg(4'000'000, 0, N);
  Z f = [&](Z &f) -> np {
    INT(x);
    --x;
    if (x != -1) {
      np rt = seg.new_root();  
      return seg.set(rt, x, 1);
    }
    np ls = f(f), rs = f(f);
    ll lsz = seg.prod(ls, 0, N), rsz = seg.prod(rs, 0, N);
    ll al = lsz * rsz;
    ll s = 0;
    if (lsz > rsz) {
      seg.enumerate(rs, [&](int idx, int) -> void {
        s += seg.prod(ls, idx, N);
      });
      ls = seg.merge(ls, rs);
    } else {
      seg.enumerate(ls, [&](int idx, int) -> void {
        s += seg.prod(rs, 0, idx);
      });
      rs = seg.merge(rs, ls);
    }
    ans += std::min(s, al - s);
    return lsz > rsz ? ls : rs;
  };
  f(f);
  print(ans);
}
#include "YRS/Z_H/main.hpp"