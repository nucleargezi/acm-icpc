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
  VEC(int, a, N);
  int s = 0;
  for (int x : a) s ^= x;
  if (s) {
    s = 0;
    FOR(i, N) {
      s ^= a[i];
      if (s) return YES(), print(2), print(1, i + 1), print(i + 2, N);
    } 
  } else {
    int e = 0, g = 0;
    FOR(i, N) {
      e ^= a[i];
      if (e) {
        FOR(k, i + 1, N) {
          g ^= a[k];
          if (g and g != e) 
            return YES(), print(3), print(1, i + 1), print(i + 2, k + 1), print(k + 2, N);
        }
        break;
      }
    }
  }
  NO();
}
#include "YRS/aa/main.hpp"