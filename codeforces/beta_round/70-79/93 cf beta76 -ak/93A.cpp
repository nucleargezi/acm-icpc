#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, l, r);
  --l, --r;
  int x = l / M, y = l % M;
  int xx = r / M, yy = r % M;
  if (x == xx or (y == 0 and (yy == M - 1 or r == N - 1))) return print(1);
  if (x + 1 == xx or (y == 0 and yy != M - 1) or 
      (y != 0 and yy == M - 1) or r == N - 1 or (y - 1 == yy)) return print(2);
  print(3);
}
#include "YRS/Z_H/main.hpp"