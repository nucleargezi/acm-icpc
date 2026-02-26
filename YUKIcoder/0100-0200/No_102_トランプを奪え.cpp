#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  VEC(int, a, 4);
  int s = 0;
  for (int x : a) s ^= x & 3;
  print(s == 0 ? "Jiro" : "Taro");
}
#include "YRS/aa/main.hpp"