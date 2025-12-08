#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/line/mat_op.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
using MT = matrix_op<RE>;
using X = MT::X;
constexpr RE eps = 1e-12;
bool f(RE x) { return std::abs(x) <= eps; }
X solve(X A, vc<RE> B = {}) {
  const int N = len(A), M = len(A[0]);
  if (B.empty()) B.resize(N, 0);
  assert(N == len(B));
  int rk = 0;
  FOR(j, M) {
    if (rk == N) break;
    FOR(i, rk, N) if (not f(A[i][j])) {
      swap(A[rk], A[i]);
      swap(B[rk], B[i]);
      break;
    }
    if (f(A[rk][j])) continue;
    RE c = RE(1) / A[rk][j];
    for (RE &x : A[rk]) x *= c;
    B[rk] *= c;
    FOR(i, N) if (i != rk) {
      RE c = A[i][j];
      if (f(c)) continue;
      B[i] -= B[rk] * c;
      FOR(k, j, M) { A[i][k] -= A[rk][k] * c; }
    }
    ++rk;
  }
  FOR(i, rk, N) if (not f(B[i])) return {};
  vc<vc<RE>> res(1, vc<RE>(M));
  vc<int> pv(M, -1);
  int p = 0;
  FOR(i, rk) {
    while (f(A[i][p])) ++p;
    res[0][p] = B[i];
    pv[p] = i;
  }
  FOR(j, M) if (pv[j] == -1) {
    vc<RE> x(M);
    x[j] = -1;
    FOR(k, j) if (pv[k] != -1) x[k] = A[pv[k]][j];
    res.ep(x);
  }
  return res;
}
void Yorisou() {
  INT(N, M);
  vc<int> in(N);
  VEC(PII, e, M);
  for (Z &[x, y] : e) {
    --x, --y;
    ++in[x], ++in[y];
  }
  MT::X a = MT::make(N, N);
  vc<RE> b(N);
  FOR(i, N) a[i][i] = 1;
  b[0] = 1;
  for (Z [x, y] : e) {
    if (x != N - 1 and y != N - 1) {
      a[x][y] -= RE(1) / in[y];
      a[y][x] -= RE(1) / in[x];
    }
  }
  vc<RE> r = solve(a, b)[0];
  vc<RE> c(M);
  FOR(i, M) {
    Z [x, y] = e[i];
    if (x != N - 1) c[i] += r[x] / in[x];
    if (y != N - 1) c[i] += r[y] / in[y];
  }
  sort(c, greater());
  RE ans = 0;
  FOR(i, M) ans += (i + 1) * c[i];
  setp(3);
  print(ans);
}
#include "YRS/Z_H/main.hpp"