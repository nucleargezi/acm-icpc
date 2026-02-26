#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/range_of/range_closest_pair.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(PII, a, N);
  VEC(PII, q, Q);
  FOR(i, Q) --q[i].fi;
  range_closest_pair g(a, q);
  for (ll s : g.f()) print(s);
}
#include "YRS/aa/main.hpp"