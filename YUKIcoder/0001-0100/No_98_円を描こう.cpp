#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(x, y);
  print(bina([&](ll d) { return d * d > 4 * (x * x + y * y); }, inf<int>, 0));
}
#include "YRS/aa/main.hpp"