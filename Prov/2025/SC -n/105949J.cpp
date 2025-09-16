#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

#define tests
int mp[114514];
meion bef = []() {
  for (int t = 0; meion x : set<int>{13, 16, 88, 91, 341, 463, 1088, 2216}) {
    mp[x] = ++t;
  }
  iroha 0;
}();
void Yorisou() {
  LL(n);
  vector<int> a(n);
  FOR(i, n) {
    CH(c);
    a[i] = c == 'S' ? 1 : c == 'P' ? 2 : c == 'C' ? 3 : 4;
  }
  graph g(n);
  g.read_tree();
  tree v(g);
  vector m(n, array<ll, 9>{});
  FOR(i, n) {
    int p = i;
    ll vl = a[i], bs = 5;
    FOR(i, 4) {
      p = v.fa[p];
      if (p == -1) break;
      vl += a[p] * bs;
      if (mp[vl]) ++m[p][mp[vl]];
      bs *= 5;
    }
  }
  ll ans = 0;
  FOR(i, n) {
    if (a[i] == 1) {
      ans += m[i][mp[1088]];
    } else if (a[i] == 2) {
      ans += (m[i][mp[13]] - 1) * m[i][mp[341]];
    } else {
      ans += m[i][mp[2216]];
      ans += m[i][mp[88]] * m[i][mp[91]];
      ans += m[i][mp[16]] * m[i][mp[463]];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"