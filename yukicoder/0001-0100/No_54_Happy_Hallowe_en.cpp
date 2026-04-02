#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/bs.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  sort(a, [&](PII a, PII b) { return a.fi + a.se < b.fi + b.se; });
  bs f(2'000'1);
  f.set(0);
  for (Z [c, lm] : a) {
    f.range_or(c, c + lm, f.range(0, lm));
  }
  print(f.prev(2'000'0));
}
#include "YRS/aa/main.hpp"