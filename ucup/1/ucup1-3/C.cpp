#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int ans = 0, N = len(s);
  FOR(i, N - 3) {
    if (s.substr(i, 4) == "ania") s[i + 3] = ' ', ++ans;
  }
  print(ans);
}
#include "YRS/aa/main.hpp"