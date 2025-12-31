#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(string, s, N);
  string r;
  FOR(i, N) {
    if (r.empty()) r += s[i];
    else r = min(r + s[i], s[i] + r);
  }
  print(r);
}
#include "YRS/aa/main.hpp"