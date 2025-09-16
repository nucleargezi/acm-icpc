#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/dsu.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  for (int &x : a) --x;
  for (int &x : b) --x;

  dsu g(N);
  FOR(i, N) g.merge(i, a[i]);
  int s = 0;
  vector<u8> vis(N);
  vector<int> ans;
  for (int x : b) {
    x = g[x];
    if (not vis[x]) {
      vis[x] = 1;
      s += g.size(x);
    }
    ans.emplace_back(s);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"