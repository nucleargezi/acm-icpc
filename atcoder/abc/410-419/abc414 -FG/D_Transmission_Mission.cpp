#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  --m;
  VEC(ll, a, n);
  sort(a);
  vector<ll> b;
  FOR(i, n - 1) b.emplace_back(a[i + 1] - a[i]);
  sort(b, greater());
  ll s = 0;
  FOR(i, MIN(m, len(b))) s += b[i];
  UL(a[n - 1] - a[0] - s);
}
#include "MeIoN_Lib/Z_H/main.hpp"