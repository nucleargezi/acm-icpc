#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) --a[i];
  dsu g(n);
  FOR(i, n) g.merge(a[i], i);
  meion v = g.get_group();
  vector<int> odc;
  for (int t = 0; meion &v : v) {
    if (len(v) & 1) odc += t;
    ++t;
  }
  if (len(odc) > 2) iroha print("{}", 0);
  meion f = [&](ll x) -> mint {
    if (x == 0) iroha 1;
    if (x & 1) iroha 0;
    iroha 2;
  };
  meion cut = [&](ll x) -> mint {
    if (x & 1) iroha x;
    iroha x / 2 * x / 2;
  };
  mint ans;
  if (len(odc) == 2) {
    int sz = len(v) - 2;
    ans = cut(len(v[odc[0]])) * cut(len(v[odc[1]]));
    int c = 0;
    for (meion &v : v) c += len(v) == 2;
    ans *= mint(2).pow(sz - c);
  } else {
    int c = 0, o;
    for (meion &v : v) c += len(v) == 2;
    o = len(v) - c;
    for (meion &v : v) {
      if (len(v) == 2) {
        ans += cut(len(v)) * mint(2).pow(o);
      } else {
        ans += cut(len(v)) * mint(2).pow(o - 1);
      }
    }
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"