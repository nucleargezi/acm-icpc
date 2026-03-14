#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
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
  subtree_hash hsh(v);
  int k = 0;
  hash_map<int> mp(N);
  vector<int> ans(N);
  FOR(i, N) {
    ull x = hsh.get(i, 0);
    if (not mp.contains(x)) mp[x] = k++;
    ans[i] = mp[x];
  }
  print(k);
  print(ans);
}
#include "YRS/Z_H/main.hpp"