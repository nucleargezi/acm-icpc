#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/subtree_hash.hpp"

// #define tests
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  subtree_hash h(v);
  hash_map<u8> mp;
  FOR(i, N) mp[h[i]] = 1;

  graph ng(N + 1);
  ng.read_tree();
  tree nv(ng);
  subtree_hash nh(nv);
  vector in = ng.deg_array();
  int ans = inf<int>;
  FOR(i, N + 1) if (in[i] == 1) {
    for (Z &&e : ng[i]) {
      if (mp.contains(nh.get(e.to, i))) {
        chmin(ans, i + 1);
      }
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"