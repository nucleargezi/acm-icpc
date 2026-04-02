#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"

// #define tests
void Yorisou() {
  int n, m, q;
  while (IN(n, m, q)) {
    int a[n], b[n];
    int l[m], r[m];
    FOR(i, m) IN(l[i], r[i]), --l[i];
    vector<int> pr[m][n];
    vector<int> ls[m];
    FOR(rs, m) {
      FOR(i, n) a[i] = i;
      FOR(i, n) b[i] = i;
      FOR(i, rs) std::reverse(a + l[i], a + r[i]);
      FOR(i, m) std::reverse(b + l[(i + rs) % m], b + r[(i + rs) % m]);
      vector<int> id(n, -1);
      bool vis[n]{};
      FOR(i, n) if (not vis[i]) {
        int sz = 0, x = i;
        vector<int> r;
        while (not vis[x]) {
          vis[x] = 1;
          id[x] = sz++;
          r.emplace_back(x);
          x = b[x];
        }
        pr[rs][sz - 1].resize(sz);
        for (int x : r) {
          if (id[a[x]] == -1) continue;
          ++pr[rs][sz - 1][(id[x] - id[a[x]] + sz) % sz];
        }
        for (int x : r) id[x] = -1;
        ls[rs].emplace_back(sz);
      }
      unique(ls[rs]);
    }
    FOR(q) {
      LL(k);
      int rs = k % m, t = k / m, ans = 0;
      for (int l : ls[rs]) ans += pr[rs][l - 1][t % l];
      UL(ans);
    }
  }
}
#include "YRS/Z_H/main.hpp"