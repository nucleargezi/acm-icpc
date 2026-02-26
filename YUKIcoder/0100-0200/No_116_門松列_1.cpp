#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = 0;
  FOR(i, 1, N - 1) {
    if (a[i] == a[i - 1] or a[i] == a[i + 1] or a[i - 1] == a[i + 1]) continue;
    if (a[i - 1] < a[i] and a[i] < a[i + 1]) continue;
    if (a[i - 1] > a[i] and a[i] > a[i + 1]) continue;
    ++s;
  }
  print(s);
}
#include "YRS/aa/main.hpp"