#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"

void Yorisou() {
  INT(N, M, Q);
  VEC(int, p, M);
  for (int &x : p) --x;
  p = inverse(p);

  constexpr int n = 30;
  vc<int> up[n];
  FOR(i, n) sh(up[i], M);
  FOR(i, M - 1) up[0][i] = p[i + 1];
  up[0][M - 1] = M;
  FOR(i, 1, n) FOR(k, M) {
    int f = up[i - 1][k];
    if (f < M) up[i][k] = up[i - 1][f];
    else up[i][k] = f + (1 << (i - 1));
  }

  Z f = [&](int x, int k) -> int {
    FOR(i, n) if (k >> i & 1) {
      if (x < M) x = up[i][x];
      else x += 1 << i;
    }
    return x;
  };

  FOR(Q) {
    INT(x);
    --x;
    if (x < M - 1) x = f(M - 2 - x, N - M + 1);
    else x = f(p[0], N - x - 1);
    print(x + 1);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"