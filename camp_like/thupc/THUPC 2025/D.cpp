#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/max_flow.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(int, d, N);
  VEC(int, a, N);
  int s = N + N, t = s + 1;
  max_flow<int> FL(t + 1, s, t);
  FOR(i, N) {
    if (d[i] == -1) FL.add(i, i + N, a[i]);
    else {
      FL.add(i, i + N, inf<int>);
      FL.add(i + N, i, inf<int>);
      if (d[i] == 0) FL.add(s, i, a[i]);
      else FL.add(i + N, t, a[i]);
    }
  }
  FOR(M) {
    INT(x, y);
    --x, --y;
    FL.add(x, y, inf<int>);
    FL.add(y + N, x + N, inf<int>);
  }
  print(FL.flow());
}
#include "YRS/aa/main.hpp"