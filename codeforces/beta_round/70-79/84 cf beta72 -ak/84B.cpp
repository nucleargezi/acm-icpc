#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/run_length.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  ll ans = 0;
  for (Z [x, c] : run_length(a)) 
    ans += c * (c + 1) / 2;
  print(ans);
}
#include "YRS/Z_H/main.hpp"