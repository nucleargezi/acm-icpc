#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  VEC(PII, e, m);
  int s = n + m, t = s + 1;
  max_flow FL(t + 1, s, t);
  FOR(i, n) {
    FL.add(i, t, a[i]);
  }
  FOR(i, m) {
    meion &[x, y] = e[i];
    FL.add(s, n + i, 1);
    FL.add(n + i, --x, 1);
    FL.add(n + i, --y, 1);
  }
  UL(m - FL.flow());
  string ans(m, '0');
  for (meion [f, to, w] : FL.get_flow_edges()) {
    if (f > n - 1) {
      f -= n;
      if (to == e[f].first) ++ans[f];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"