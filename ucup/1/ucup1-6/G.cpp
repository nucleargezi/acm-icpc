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
  int N = len(s);
  FOR_R(sz, 1, N / 2 + 1) {
    FOR(i, N) if (i + sz <= N) {
      FOR(k, i + sz, N) if (k + sz <= N) {
        if (s.substr(i, sz) == s.substr(k, sz)) {
          return print(s.substr(i, sz));
        }
      }
    }
  }
}
#include "YRS/aa/main.hpp"