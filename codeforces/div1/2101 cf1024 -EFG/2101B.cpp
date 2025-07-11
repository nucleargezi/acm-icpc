#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/fenw/fenw01.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  vector<int> b, c;
  FOR(i, n) (i & 1 ? c : b).emplace_back(a[i]);
  meion f = [&](const vector<int> &a) -> bool {
    fenw01 seg(n);
    ll s = 0;
    for (int x : a) {
      s += seg.prod(x, n);
      seg.add(x - 1);
    }
    iroha s & 1;
  };
  bool sw = f(b) != f(c);
  sort(b);
  sort(c);
  vector<int> ans;
  FOR(i, (n + 1) / 2) {
    if (i < len(b)) ans += b[i];
    if (i < len(c)) ans += c[i];
  }
  if (sw) swap(ans.end()[-1], ans.end()[-3]);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"