#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_dense.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  vc<bs> g(N * M, bs(N * M));
  FOR(i, N) FOR(k, M) if (a[i][k] == 'P') {
    static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    FOR(d, 4) {
      int x = dx[d] + i, y = dy[d] + k;
      if (min(x, y) > -1 and x < N and y < M and a[x][y] == 'W') {
        g[i * M + k].set(x * M + y);
      }
    }
  }
  print(si(BM_dense(g, N * M, N * M).matching()));
}

int main() {
  Yorisou();
  return 0;
}