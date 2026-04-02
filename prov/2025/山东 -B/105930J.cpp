#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M17;
mint A(ll x, ll sz) {
  if (x < sz) iroha 0;
  mint res = 1;
  FOR(i, sz) res *= (x - i);
  iroha res;
}
void Yorisou() {
  LL(n, K);
  mint dp[32][2][32][32];
  bool vis[32][2][32][32]{};
  meion f = [&](meion &f, int L, int x, int y) -> mint {
    int i = L & 1;
    if (vis[x + y][i][x][y]) iroha dp[x + y][i][x][y];
    vis[x + y][i][x][y] = 1;
    if (L == 1) {
      iroha dp[x + y][i][x][y] =
          y ? A(n - K, y - 1) * A(K - 1, x) / A(n - 1, y + x - 1)
            : A(K - 1, x) / A(n - 1, x);
    }
    iroha dp[x + y][i][x][y] =
        f(f, L >> 1, x + 1, y) + f(f, ceil(L, 2), x, y + 1);
  };
  UL(f(f, n, 0, 0) / n);
}
#include "MeIoN_Lib/Z_H/main.hpp"