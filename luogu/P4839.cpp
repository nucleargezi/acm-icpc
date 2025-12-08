#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct Seg {
  struct X {
    vc<int> a;
    void add(int x) {
      for (int y : a) chmin(x, x ^ y);
      if (x) a.ep(x);
    }
  };
  vc<X> a;
  int N, log, sz;
  Seg(int M) {
    N = M, log = 1;
    while ((1 << log) < N) ++log;
    sz = 1 << log;
    a.resize(sz << 1);
  }
  
  void upd(int i, int x) {
    a[i += sz].add(x);
    while (i >>= 1) a[i].add(x);
  }

  int prod(int l, int r) {
    l += sz, r += sz;
    X x;
    while (l < r) {
      if (l & 1) for (int e : a[l++].a) x.add(e);
      if (r & 1) for (int e : a[--r].a) x.add(e);
      l >>= 1, r >>= 1;
    }
    for (r = 0; int e : x.a) chmax(r, r ^ e);
    return r;
  }
};
void Yorisou() {
  INT(Q, N);
  Seg seg(N);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.upd(i, x);
    } else {
      INT(l, r);
      --l;
      print(seg.prod(l, r));
    }
  }
}
#include "YRS/Z_H/main.hpp"