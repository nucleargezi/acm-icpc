#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int sz = 2'000'00;
int mem[sz][100];
void Yorisou() {
  LL(N, K);
  VEC(int, e, K);
  sort(e);
  memset(mem, -1, sizeof mem);
  Z f = [&](Z &f, int p, ll s) -> ll {
    if (p == 0 or s == 0) return s;
    if (s < sz) {
      if (mem[s][p - 1] == -1)
        mem[s][p - 1] = f(f, p - 1, s) - f(f, p - 1, s / e[p - 1]);
      return mem[s][p - 1];
    }
    return f(f, p - 1, s) - f(f, p - 1, s / e[p - 1]);
  };
  print(f(f, K, N));
}
#include "YRS/Z_H/main.hpp"