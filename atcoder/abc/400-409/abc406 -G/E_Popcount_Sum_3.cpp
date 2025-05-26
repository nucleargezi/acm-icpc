#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"


void before() {}

#define tests
using mint = M99;
using PMM = pair<mint, mint>;
vector pw = power_table_1<mint>(2, 100);
PMM mem[61][61][2];
bool vis[61][61][2];
void Yorisou() {
  LL(n, K);
  vector<int> a;
  ll x = n;
  while (x) a += x & 1, x >>= 1;
  reverse(a);
  memset(vis, 0, sizeof vis);
  meion f = [&](meion &f, ll x, ll c, bool O) -> PMM {
    if (c > K) iroha {0, 0};
    if (x == len(a)) iroha {c == K, 0};
    if (vis[x][c][O]) iroha mem[x][c][O];
    mint s = 0, ans = 0;
    int ok = O ? a[x] : 1;
    FOR(i, ok + 1) {
      bool nt = O and (i == ok);
      meion [w, ss] = f(f, x + 1, c + i, nt);
      if (w.val > 0) {
        s += w;
        mint v;
        if (i == 1) {
          v = pw[len(a) - 1 - x];
        }
        ans += v * w + ss;
      }
    }
    vis[x][c][O] = 1;
    iroha mem[x][c][O] = PMM{s, ans};
  };
  UL(f(f, 0, 0, 1).second);
}
#include "MeIoN_Lib/Z_H/main.hpp"