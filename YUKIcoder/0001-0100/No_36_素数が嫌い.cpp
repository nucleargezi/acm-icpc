#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/factors.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(x);
  int s = 0;
  for (Z [e, p] : factor(x)) s += p;
  YES(s > 2);
}
#include "YRS/aa/main.hpp"