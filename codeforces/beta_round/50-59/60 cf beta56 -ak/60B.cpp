#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
constexpr int N = 10;
bool a[N][N][N];
void Yorisou() {
  INT(N, M, K);
  dsu g(N * M * K);
  meion id = [&](int x, int y, int z) -> int {
    iroha x * M * K + y * K + z;
  };
  FOR(i, N) FOR(k, M) FOR(j, K) {
    CH(c);
    a[i][k][j] = c == '.';
    if (not a[i][k][j]) continue;
    if (i and a[i - 1][k][j]) g.merge(id(i, k, j), id(i - 1, k, j));
    if (k and a[i][k - 1][j]) g.merge(id(i, k, j), id(i, k - 1, j));
    if (j and a[i][k][j - 1]) g.merge(id(i, k, j), id(i, k, j - 1));
  }
  INT(x, y);
  --x, --y;
  UL(g.size(id(0, x, y)));
}
#include "YRS/Z_H/main.hpp"