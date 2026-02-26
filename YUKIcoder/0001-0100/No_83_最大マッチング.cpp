#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N);
  string s(N >> 1, '1');
  if (N & 1) s[0] = '7';
  print(s);
}
#include "YRS/aa/main.hpp"