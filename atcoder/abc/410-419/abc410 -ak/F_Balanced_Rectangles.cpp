#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(string, s, n);
  if (n > m) {
    vector<string> t(m, string(n, ' '));
    FOR(i, n) FOR(k, m) t[k][i] = s[i][k];
    swap(n, m);
    s.swap(t);
  }
  int a[n][m];
  FOR(i, n) FOR(k, m) {
    a[i][k] = s[i][k] == '#' ? 1 : -1;
  }
  ll ans = 0;
  vector<ll> prs(m);
  std::unordered_map<ll, int> c;
  c.reserve(m << 1);
  c.max_load_factor(0.25f);
  FOR(i, n) {
    fill(prs, 0);
    for (int k = i; k < n; ++k) {
      for (int j = 0; j < m; ++j) {
        prs[j] += a[k][j];
      }
      c.clear();
      c[0] = 1;
      ll s = 0;
      for (int j = 0; j < m; ++j) {
        s += prs[j];
        if (c.contains(s)) {
          ans += c[s];
        }
        ++c[s];
      }
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"