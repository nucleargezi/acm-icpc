#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  map<int, int> mp;
  INT(N);
  FOR(N) {
    INT(x);
    ++mp[-x];
  }
  int s = 0;
  for (int mx = -1; PII e : mp) if (chmax(mx, e.se)) s = -e.fi;
  print(s);
}
#include "YRS/aa/main.hpp"