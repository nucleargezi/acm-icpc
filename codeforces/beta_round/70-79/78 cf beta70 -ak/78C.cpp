#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/divisors.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
void Timur(bool o = true) { print(o ? "Timur" : "Marsel"); }
void Marsel(bool o = true) { Timur(not o); }
void Yorisou() {
  INT(N, M, K);
  if (~N & 1) return Marsel();
  for (Z e : divisor(M)) {
    if (e < K or e == M) continue;
    return Timur();
  }
  Marsel();
}
#include "YRS/Z_H/main.hpp"