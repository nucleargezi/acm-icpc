#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/subtree_hash.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N);
  vc<ull> a(N);
  vc<vc<int>> g;
  FOR(i, N) {
    INT(N);
    g.assign(N, {});
    FOR(i, N) {
      INT(f);
      --f;
      if (f == -1) continue;
      g[f].ep(i), g[i].ep(f);
    }
    ull mx = 0;
    tree_hash v(g);
    FOR(i, N) chmax(mx, v[i]);
    a[i] = mx;
  }
  hashmap<int> mp(N);
  FOR(i, N) {
    if (not mp.contains(a[i])) mp[a[i]] = i + 1;
    print(mp[a[i]]);
  }
}

int main() { Yorisou(); }