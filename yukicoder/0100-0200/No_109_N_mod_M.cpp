#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/fac.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, M);
  print(factorial(N, M));
}
#include "YRS/aa/main.hpp"