#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, d);
  VEC(int, a, N);
  vector<vector<int>> v(N);
  FOR(i, N) v[a[i]].ep(i);
  Z check = [&](vector<int> &v) -> bool {
    if (v.empty()) return true;
    const int M = len(v);
    vector<int> g;
    FOR(i, 1, M) {
      int x = v[i - 1], y = v[i];
      if (y - x > d) g.ep(y);
    }
    g.ep(N + d + d);
    int i = -1, ls = -1;
    while (i <= v.back()) {
      i = v[lower_bound(v, i)];
      int x = g[upper_bound(g, i)];
      int y = v[lower_bound(v, x) - 1];
      if (y - i + 1 > d) return false;
      if (ls + d + d >= x) return false;
      ls = std::max(ls + d + d, y + d);
      i = ls + 1;
    }
    return true;
  };
  FOR(i, N) {
    if (check(v[i])) return print(i);
  }
  print(N);
}
#include "YRS/Z_H/main.hpp"