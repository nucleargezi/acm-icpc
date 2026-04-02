#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using re = ld;
struct pl {
  re p;
  vc<int> a;

  pl(re p, const vc<int> &a) : p(p), a(a) {}

  int f() {
    int sz = len(a);
    if (sz == 1) return pop(a);
    re t = (re)rng(1'000'001) / 1'000'000;
    if (t <= p) return pop(a);
    int i = rng(sz - 1), s = a[i];
    a.erase(begin(a) + i);
    return s;
  }
};
void Yorisou() {
  INT(N);
  REAL(pa, pb);
  VEC(int, ca, N);
  VEC(int, cb, N);
  sort(ca, greater());
  sort(cb, greater());

  int s = 0;
  FOR(2'000'000) {
    int A = 0, B = 0;
    pl a(pa, ca), b(pb, cb);
    FOR(N) {
      int l = a.f(), r = b.f();
      (l > r ? A : B) += l + r;
    }
    s += A > B;
  }
  setp(10);
  print(s / 2'000'000.l);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"