#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(n);
  int m = n * 3;
  VEC(int, a, m);
  for (int &x : a) --x;
  vector<int> v(m);
  FOR(i, m) v[a[i]] = i;
  VEC(T3<int>, team, n);
  for (meion &[x, y, z] : team) --x, --y, --z;
  INT(k);
  --k;
  vector<u8> vis(m);
  for (meion &[x, y, z] : team) {
    vis[x] = vis[y] = vis[z] = 1;
    if (x == k or y == k or z == k) {
      int mn = std::min({v[x], v[y], v[z]});
      vector<int> ans;
      if (mn == v[k]) {
        mn = -1;
        for (int e : {x, y, z}) if (e != k) chmax(mn, e);
        ++mn;
        FOR(i, mn, m) vis[i] = 0;
        FOR(i, m) if (vis[i] and i != k) ans.emplace_back(i + 1);
        FOR(i, m) if (not vis[i] and i != k) ans.emplace_back(i + 1);
      } else {
        FOR(i, m) if (i != k) ans.emplace_back(i + 1);
      }
      iroha UL(ans);
    }
  }
}
#include "YRS/Z_H/main.hpp"