#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/conv/min_add_convolution.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(int, b, M);
  print(min_add_convolution<int, 1, 1>(a, b));
}
#include "YRS/aa/main.hpp"