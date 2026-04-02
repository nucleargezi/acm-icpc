#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(a, b, c);
  print(bina([&](int x) -> bool {
    int s = 0;
    for (int e : {a, b, c}) {
      e -= x;
      if (e < 0) s += e;
      else s += e / 2;
    }
    return s >= 0;
  }, 0, max({a, b, c}) + 1));
}
#include "YRS/aa/main.hpp"