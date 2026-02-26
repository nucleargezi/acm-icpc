#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/flow/max_flow.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  INT(M);
  VEC(PII, e, M);

  int s = 2 * N, t = s + 1;
  max_flow<int> g(t + 1, s, t);
  FOR(i, N) g.add(i, i + N, inf<int>);
  FOR(i, N) g.add(s, i, a[i].fi);
  FOR(i, N) g.add(i + N, t, a[i].se);
  for (Z [x, y] : e) g.add(x, y + N, inf<int>);
  int al = 0;
  for (Z [x, y] : a) al += x + y;
  print(al - g.flow());
}
#include "YRS/aa/main.hpp"