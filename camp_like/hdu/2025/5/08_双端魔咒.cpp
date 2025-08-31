#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/string/acam.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests

void Yorisou() {
  LL(n, m);
  VEC(string, a, n);
  VEC(string, b, m);
  S(s);

  for (meion &s : a) reverse(s);
  AC L;
  L.add(a);
  L.work();
  meion A = reversed(L.get_end_min(reversed(s)));

  AC R;
  R.add(b);
  R.work();
  meion B = R.get_end_min(s);

  const int N = len(s);
  vector<vector<int>> v(N);
  FOR(i, N) if (A[i] != inf<int>) {
    v[A[i] + i - 1].emplace_back(A[i]);
  }
  ll ans = 0;
  fenw<monoid_add<ll>> seg(N);
  FOR(i, N) {
    for (int sz : v[i]) {
      seg.multiply(i - sz + 1, 1);
    }
    if (B[i] != inf<int>) {
      ans += seg.prod(0, i - B[i] + 1 + 1);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"