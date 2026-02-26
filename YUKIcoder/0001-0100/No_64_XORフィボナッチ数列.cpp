#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(a, b, N);
  vc<ll> f(10);
  f[0] = a, f[1] = b;
  f[2] = a ^ b;
  print(f[N % 3]);
}
#include "YRS/aa/main.hpp"