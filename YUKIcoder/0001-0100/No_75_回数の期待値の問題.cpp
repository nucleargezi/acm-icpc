#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/line/mat.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  mat<ld> a(N, 1);
  FOR(i, N) FOR(k, 1, 7) {
    if (i + k < N) a[i][i + k] -= 1.l / 6;
    else if (i + k > N) a[i][0] -= 1.l / 6;
  }
  a = get<2>(a.inv());
  re s = 0;
  FOR(i, N) s += a[0][i];
  print(s);
}
#include "YRS/aa/main.hpp"