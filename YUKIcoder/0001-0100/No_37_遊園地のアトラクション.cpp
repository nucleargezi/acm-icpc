#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/01.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(V, N);
  VEC(int, w, N);
  VEC(int, v, N);
  FOR(i, N) {
    int x = v[i];
    while (x >>= 1) w.ep(w[i]), v.ep(x);
  }
  print(knapsack01(w, v, V));
}
#include "YRS/aa/main.hpp"