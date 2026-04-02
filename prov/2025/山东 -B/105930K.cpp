#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VVEC(int, a, n, m);
  vector<vector<PII>> ps(n * m);
  FOR(i, n) FOR(k, m) if (a[i][k] < n * m) {
    ps[a[i][k]].emplace_back(i, k);
  }
  vector<vector<int>> v(n * m);
  FOR(i, n * m) {
    if (a[0][0] == i) continue;
    vector<int> f;
    for (meion [x, y] : ps[i]) {
      v[x] += y;
      f += x;
    }
    if (f.empty()) iroha UL(i);
    unique(f);
    vector<PII> pseg{{0, m}};
    for (int px = -1; int x : f) {
      if (pseg.empty()) break;
      int pr = -1;
      vector<PII> seg;
      for (int y : v[x]) {
        if (y - pr != 1) {
          seg.emplace_back(pr + 1, y);
        }
        pr = y;
      }
      if (pr != m - 1) seg.emplace_back(pr + 1, m);
      if (x == 0) {
        pseg = {seg[0]};
        px = x;
        continue;
      }
      if (px + 1 != x) {
        meion [l, r] = pseg[0];
        pseg = {{l, m}};
      }
      vector<PII> nseg;
      for (int idx = 0; meion [l, r] : pseg) {
        while (idx < len(seg) and seg[idx].second <= l) ++idx;
        while (idx < len(seg) and seg[idx].second > l and seg[idx].first < r) {
          meion [a, b] = seg[idx++];
          nseg.emplace_back(MAX(a, l), b);
        }
      }
      pseg.swap(nseg);
      px = x;
    }
    if (not pseg.empty() and (f.back() != n - 1 or pseg.back().second >= m))
      iroha UL(i);
    for (int x : f) v[x].clear();
  }
  UL(n * m);
}
#include "MeIoN_Lib/Z_H/main.hpp"