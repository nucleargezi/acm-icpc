#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(a, b);
  int i = 1;
  while (1) {
    if (i > b) return print(b);
    b -= i;
    i += 1;
    if (i > a) i -= a;
  }
}
#include "YRS/Z_H/main.hpp"