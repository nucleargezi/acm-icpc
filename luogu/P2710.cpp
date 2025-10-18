#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/ds/splay/splay_acted_monoid.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_sub_array_sum.hpp"

void before() {}

// #define tests
using Node = acted_monoid_max_subarray_sum<int, -15452>;
using dat = Node::X;
using Splay = splay_acted_monoid<Node>;
void Yorisou() {
  LL(n, q);
  vector<dat> a(n);
  FOR(i, n) {
    INT(x);
    a[i] = Node::from_element(x);
  }
  constexpr int N = 1'500'000;
  Splay seg(N);
  Splay::T x;
  meion &rt = seg.rt;
  rt = seg.new_node(a);
  FOR(q) {
    S(op);
    if (op == "INSERT") {
      LL(p, sz);
      vector<dat> ins(sz);
      FOR(i, sz) {
        INT(x);
        ins[i] = Node::from_element(x);
      }
      meion [l, r] = seg.split(rt, p);
      rt = seg.merge(l, seg.new_node(ins), r);
    } else if (op == "DELETE") {
      LL(p, sz);
      meion [l, m, r] = seg.split(rt, p - 1, p - 1 + sz);
      rt = seg.merge(l, r);
      seg.free_subtree(m);
    } else if (op == "MAKE-SAME") {
      LL(p, sz, c);
      seg.apply(rt, p - 1, p - 1 + sz, c);
    } else if (op == "REVERSE") {
      LL(p, sz);
      seg.reverse(rt, p - 1, p - 1 + sz);
    } else if (op == "GET-SUM") {
      LL(p, sz);
      UL(sz ? seg.prod(rt, p - 1, p - 1 + sz).s : 0);
    } else if (op == "GET") {
      LL(p);
      UL(seg.get(rt, p - 1).s);
    } else {
      LL(p, sz);
      meion res = seg.prod(rt, p - 1, p - 1 + sz);
      UL(res.mx);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"