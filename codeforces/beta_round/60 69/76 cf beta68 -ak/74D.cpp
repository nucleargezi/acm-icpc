#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/dynamic_seg_sprase.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/ds/heap/erase_heap.hpp"
#include "YRS/ds/chtholly/chtholly.hpp"

// #define tests
using Seg = dynamic_seg_sparse<monoid_add<int>>;
void Yorisou() {
  INT(N, Q);
  Seg seg(Q, 0, N);
  Z rt = seg.new_root();
  hash_map<char> vis(Q);
  hash_map<int> p(Q);

  chtholly<int, int> ch(0);
  ch.set(0, N, 1);
  max_erase_heap<pair<int, int>> q;
  q.eb(N, 0);
  
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(l, r);
      --l;
      print(seg.prod(rt, l, r));
    } else {
      int x = op - 1;
      if (vis[x] ^= 1) {
        Z [sz, l] = pop(q);
        int i = l + sz / 2;
        p[x] = i;
        rt = seg.set(rt, i, 1);
        ch.set(i, i + 1, 0);
        q.eb(i - l, l);
        q.eb(l + sz - i - 1, i + 1);
      } else {
        x = p[x];
        rt = seg.set(rt, x, 0);
        ch.set(x, x + 1, 1);
        Z [l, r, _] = ch[x];
        q.pop({x - l, l});
        q.pop({r - x - 1, x + 1});
        q.eb(r - l, l);
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"