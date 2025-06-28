#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

using mint = M99;
void Yorisou() {
  LL(n);
  static constexpr int N = 1145141;
  static int tr[N][2], t;
  static mint c[N][2];
  static bitset<N> vis;
  FOR(n) {
    SV(s, 'A');
    int n = len(s), p = 0;
    vector<int> go{0};
    c[p][0] = 1;
    FOR(i, n) {
      int x = s[i];
      if (not tr[p][x]) tr[p][x] = ++t, c[p][0] = 1;
      p = tr[p][x];
      go.emplace_back(p);
    }
    vis[p] = 1;
    for (int p : std::views::reverse(go)) {
      int lp = tr[p][0], rp = tr[p][1];
      mint la = 1, lb = 0, ra = 1, rb = 0;
      if (lp) std::tie(la, lb) = pair(c[lp][0], c[lp][1]);
      if (rp) std::tie(ra, rb) = pair(c[rp][0], c[rp][1]);
      mint mb = lb * rb, ms = (la + lb) * (ra + rb);
      c[p][0] = ms - mb;
      c[p][1] = mb;
      if (vis[p]) c[p][1] += ms;
    }
    UL(c[0][1]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"