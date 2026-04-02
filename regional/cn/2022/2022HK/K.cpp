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
  sort(a);
  int ans = a[0] / 2;
  bool o = 1;
  FOR(i, 1, N) o &= a[i] / 2 >= a[0] or a[i] % a[0] == 0;
  if (o) chmax(ans, a[0]);
  print(ans);
}
#include "YRS/aa/main.hpp"