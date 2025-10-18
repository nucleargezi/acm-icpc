#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/monoid/major_voting.hpp"
#include "YRS/ds/seg/dynamic_seg_sprase.hpp"
#include "YRS/ds/swag.hpp"
#include "YRS/ds/basic/deque.hpp"

// #define tests
using que = fast_deque<int>;
using MX = monoid_major_voting;
using X = MX::X;
using Seg = dynamic_seg_sparse<monoid_add<int>>;
using np = Seg::np;
void Yorisou() {
  INT(N, Q);
  vector<que> v(N + Q);
  vector<swag_deque<MX>> q(N + Q);
  vector<np> rt(N + Q);
  Seg seg((N + Q) << 1, 0, N + Q);
  FOR(i, N) {
    INT(sz);
    VEC(int, a, sz);
    for (int &x : a) {
      --x;
      v[i].push_back(x);
      q[i].push_back({x, 1});
    }
    rt[i] = seg.new_root();  
    for (int x : a) rt[i] = seg.multiply(rt[i], x, 1);
  }
  FOR(i, N, N + Q) rt[i] = seg.new_root();
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      v[x].push_back(y);
      q[x].push_back({y, 1});
      rt[x] = seg.multiply(rt[x], y, 1);
    } else if (op == 2) {
      INT(x);
      --x;
      int y = pop(v[x]);
      q[x].pop_back();
      rt[x] = seg.multiply(rt[x], y, -1);
    } else if (op == 3) {
      INT(sz);
      VEC(int, id, sz);
      X r = MX::unit();
      for (int &i : id) {
        --i;
        r = MX::op(r, q[i].prod());
      }
      int x = r.fi, s = 0, al = 0;
      for (int i : id) {
        al += len(v[i]);
        s += seg.prod(rt[i], x, x + 1);
      }
      print(s + s > al ? x + 1 : -1);
    } else {
      INT(x, y, z);
      --x, --y, --z;
      if (len(v[x]) > len(v[y])) {
        while (not v[y].empty()) {
          int e = v[y].pop_front();
          v[x].push_back(e);
          q[x].push_back({e, 1});
        }
        for (Z [e, c] : seg.get_all(rt[y])) {
          rt[x] = seg.multiply(rt[x], e, c);
        }
        seg.free_subtree(rt[y]);
        swap(rt[x], rt[z]);
        swap(v[x], v[z]);
        swap(q[x], q[z]);
      } else {
        while (not v[x].empty()) {
          int e = v[x].pop_back();
          v[y].push_front(e);
          q[y].push_front({e, 1});
        }
        for (Z [e, c] : seg.get_all(rt[x])) {
          rt[y] = seg.multiply(rt[y], e, c);
        }
        seg.free_subtree(rt[x]);
        swap(rt[y], rt[z]);
        swap(v[y], v[z]);
        swap(q[y], q[z]);
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"