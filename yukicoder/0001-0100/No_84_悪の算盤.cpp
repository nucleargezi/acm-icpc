#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, M);
  ll s = 0;
  if (N != M) s += (N / 2) * (M / 2) * 2;
  else s += (N / 2) * (M / 2);
  if ((N & 1) and (M & 1)) s += N / 2 + (N != M) * M / 2 + 1;
  else if (N & 1) s += M / 2;
  else if (M & 1) s += N / 2;
  print(s - 1);
}
#include "YRS/aa/main.hpp"