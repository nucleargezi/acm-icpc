#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/subtree_hash.hpp"

// #define tests
void Yorisou() {
  INT(M);
  vector<ull> a(M);
  FOR(i, M) {
    INT(N);
    graph g(N);
    FOR(i, N) {
      INT(fa);
      --fa;
      if (fa == -1) continue;
      g.add(fa, i);
    }
    g.build();
    tree v(g);
    subtree_hash H(v);
    FOR(k, N) chmax(a[i], H[k]);
  }
  hash_map<int> mp;
  FOR(i, M) {
    if (not mp.contains(a[i])) mp[a[i]] = i + 1;
    print(mp[a[i]]);
  }
}
#include "YRS/Z_H/main.hpp"