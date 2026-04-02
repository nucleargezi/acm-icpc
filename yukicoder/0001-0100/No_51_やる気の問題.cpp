#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(W, D);
  FOR_R(i, 2, D + 1) W -= W / (1ll * i * i);
  print(W);
}
#include "YRS/aa/main.hpp"