#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  INT(sz);
  VEC(PII, a, sz);
  vc<int> x, y;
  for (PII e : a) x.ep(e.fi), y.ep(e.se);
  unique(x);
  unique(y);
  print(len(x) * M + len(y) * N - sz - len(x) * len(y));
}
#include "YRS/aa/main.hpp"