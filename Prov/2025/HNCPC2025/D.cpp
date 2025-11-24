#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  int N, M;
  IN(N, M);
  if (N != M) {
    print(min(N, M));
    if (N < M) FOR(i, N) print(1, i + 1, 1);
    else FOR(i, M) print(1, 1, i + 1);
  } else {
    if (N == 1) print(1), print(1, 1, 1);
    else if (N == 2) print(2), print(1, 1, 1), print(1, 2, 2);
    else {
      print(N - 1);
      print(2, 2, 2);
      print(1, 2, 2);
      FOR(i, 3, N) print(1, i + 1, i + 1);
    }
  }
}
#include "YRS/Z_H/main.hpp"