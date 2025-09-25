#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M, K);
  dsu g(N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    g.merge(x, y);
  }
  vector<int> v;
  FOR(i, N) if (g[i] == i) v.ep(g.size(i));
  if (len(v) == 1) return print(0);
  if (K == 1) return print(len(v) - 2);
  int ans = 0, f = 0, ls = 0;
  sort(v, greater());
  for (int x : v) {
    if (not f) f = 1, ls += std::min(K, x);
    else if (not ls) ++ans, ls += std::min(K, x);
    else ls += std::min(K, x) - 2;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"