#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  int EI[10][10], t = 0;
  FOR(i, n) FOR(k, i + 1, n) EI[i][k] = t++;
  int msk = 0;
  FOR(m) {
    LL(x, y);
    --x, --y;
    if (x > y) swap(x, y);
    msk |= 1 << EI[x][y];
  }
  vector<int> I(n);
  FOR(i, n) I[i] = i;
  int ans = inf<int>;
  do {
    vector<u8> vis(n);
    int mskk = 0, f = 1;
    FOR(i, n) if (not vis[i]) {
      int l = 0, p = i;
      do {
        vis[p] = 1;
        int t = I[p], x = p, y = t;
        if (x > y) swap(x, y);
        mskk |= 1 << EI[x][y];
        p = t;
        ++l;
      } while (p != i);
      if (l < 3) {
        f = 0;
        break;
      }
    }
    if (f) chmin(ans, popcount(msk ^ mskk));
  } while (std::next_permutation(I.begin(), I.end()));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"