#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/graph/two_sat.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  vector g(k, vector(n, vector<u8>(n)));
  FOR(i, k) {
    LL(m);
    FOR(m) {
      LL(x, y);
      --x, --y;
      g[i][x][y] = g[i][y][x] = 1;
    }
  }
  TwoSat sat(n);
  FOR(i, k) {
    FOR(x, n) {
      FOR(y, x + 1, n) {
        bool f = 1;
        FOR(j, n) if (j != x and j != y)
          f &= (g[i][j][x] == g[i][j][y]);
        if (f) sat.either(x, y, g[i][x][y], g[i][x][y]);
      }
    }
  }
  Yes(sat.solve());
}
#include "MeIoN_Lib/Z_H/main.hpp"