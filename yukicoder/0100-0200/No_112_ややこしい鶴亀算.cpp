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
  map<int, int> mp;
  for (int x : a) ++mp[-x];
  if (len(mp) == 1) {
    if (a[0] / (N - 1) == 2) print(N, 0);
    else print(0, N);
  } else {
    vc<int> s;
    for (PII x : mp) s.ep(x.se);
    print(s);
  }
}
#include "YRS/aa/main.hpp"