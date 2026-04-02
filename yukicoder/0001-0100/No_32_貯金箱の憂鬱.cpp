#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(c, b, a);
  b += a / 25;
  a %= 25;
  c += b / 4;
  b %= 4;
  print(a + b + c % 10);
}
#include "YRS/aa/main.hpp"