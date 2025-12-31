#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/lazy_seg_sprase.hpp"
#include "YRS/ds/a_monoid/xor_or.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr ull lm = 2'000'000'000ull;
ull N;
inline static ull L(ull i) { return i > lm ? N + 1 : min(N + 1, i * (i - 1) / 2 + 2); }
inline static ull R(ull i) { return i > lm ? N : min(N, i * (i + 1) / 2 + 1); }
void Yorisou() {
  IN(N);
  INT(Q);
  vc<pair<ull, ull>> ops;
  ops.reserve(Q);
  vc<ull> f{1, N + 1};
  f.reserve(Q * 18);
  FOR(Q) {
    INT(op);
    ull x, w;
    IN(x);
    if (op == 1) IN(w);
    else w = 0;
    ops.ep(x, w);
    f.ep(x), f.ep(x + 1);
    ull l = x, r = x;
    while (1) {
      l = L(l), r = R(r);
      if (l > N) break;
      f.ep(l), f.ep(r + 1);
    }
  }
  unique(f);
  lazy_seg_sprase<a_monoid_xor_or<ull>> seg(f);
  for (Z [x, w] : ops) {
    if (w == 0) {
      ull s = seg.prod(x, x + 1), l = x, r = x;
      while (1) {
        l = L(l), r = R(r);
        if (l > N) break;
        s ^= seg.prod(l, r + 1);
      }
      print(s);
    } else {
      seg.apply(x, x + 1, w);
      ull l = x, r = x;
      while (1) {
        l = L(l), r = R(r);
        if (l > N) break;
        seg.apply(l, r + 1, w);
      }
    }
  }
}
#include "YRS/aa/main.hpp"