#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/tr/subtree_hash.hpp"

void Yorisou() {
  INT(N);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    g.add(f, i);
  }
  g.build();
  hld v(g);
  subtree_hash hs(v);
  int t = 0;
  hashmap<int> mp(N);
  vc<int> rs(N);
  FOR(i, N) {
    ull x = hs.get(i, 0);
    if (not mp.contains(x)) mp[x] = t++;
    rs[i] = mp[x];
  }
  print(t);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}