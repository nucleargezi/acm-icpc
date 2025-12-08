#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/ds/wave/wave_mat_sim.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, Q);
  VEC(int, h, N);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e);
  dsu f(N + N - 1);
  graph g(N + N - 1);
  vc<int> val(N + N - 1);
  int nt = N;
  for (Z [w, x, y] : e) {
    x = f[x], y = f[y];
    if (x != y) {
      g.add(nt, x);
      g.add(nt, y);
      f.set(nt, x);
      f.set(nt, y);
      val[nt] = w;
      ++nt;
    }
  }
  if (nt != N + N - 1) {
    FOR(i, nt) if (f[nt] != f[i]) {
      g.add(nt, f[i]);
      f.set(nt, f[i]);
    }
    val[nt++] = inf<int>;
  }
  g.build();
  tree v(g, nt - 1);
  vc<int> I(N);
  FOR(i, N) I[i] = v.L[i];
  vc<int> t = argsort(I);
  h = rearrange(h, t);
  I = rearrange(I, t);
  wave_matrix_sim wm(h);
  FOR(Q) {
    INT(x, lm, K);
    --x;
    x = v.max_path([&](int x) { return val[x] <= lm; }, x, N + N - 2);
    int l = lb(I, v.L[x]), r = lb(I, v.R[x]);
    if (r - l < K) print(-1);
    else print(wm.kth(l, r, r - l - K));
  }
}
#include "YRS/Z_H/main.hpp"