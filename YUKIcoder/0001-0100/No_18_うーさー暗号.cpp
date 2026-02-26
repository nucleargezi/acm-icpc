#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s);
  FOR(i, N) s[i] = (s[i] - 'A' - (i + 1) % 26 + 26) % 26 + 'A';
  print(s);
}
#include "YRS/aa/main.hpp"