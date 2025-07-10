#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  if (K == 1) iroha YES();
  vector sa(a);
  sort(sa);
  int w = sa[K - 2];
  vector<ll> v;
  FOR(i, n) if (a[i] < w + 1) v += a[i];
  int c = 0;
  for (int i = 0, k = len(v) - 1; i < k; ) {
    if (v[i] == v[k]) {
      ++i, --k;
    } else if (v[i] == w) {
      ++i, ++c;
    } else if (v[k] == w) {
      --k, ++c;
    } else {
      iroha NO();
    }
  }
  YES(c <= len(v) - K + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"