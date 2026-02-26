#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(a, b, p);
  int sa = abs(a - p), sb = abs(b - p);
  if (p == 1 or sa <= sb) return print(sa + p);
  if (a != 0) return print(sb + a + min(p - 1, sa));
  print(sb + p + 1);
}
#include "YRS/aa/main.hpp"