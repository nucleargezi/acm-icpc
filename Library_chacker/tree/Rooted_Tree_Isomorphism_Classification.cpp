#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/subtree_hash.hpp"

// #define tests
void Yorisou() {
  INT(N);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    g.add(f, i);
  }
  g.build();
  tree v(g);
  subtree_hash H(v);
  hash_map<int> mp;
  int t = 0;
  vector<int> ans(N);
  FOR(i, N) {
    ull g = H.get(i, 0);
    if (not mp.contains(g)) mp[g] = t++;
    ans[i] = mp[g];
  }
  print(t);
  print(ans);
}
#include "YRS/Z_H/main.hpp"