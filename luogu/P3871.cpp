#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/wave/wave_mat_sim.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  INT(Q);
  vc<int> g(Q);
  FOR(i, Q) {
    STR(op);
    if (op[0] == 'a') IN(g[i]), a.ep(g[i]);
    else g[i] = -inf<int>;
  }
  wave_matrix_sim<int> wm(a);
  for (int x : g) {
    if (x == -inf<int>) print(wm.median(0, 0, N));
    else ++N;
  }
}
#include "YRS/aa/main.hpp"