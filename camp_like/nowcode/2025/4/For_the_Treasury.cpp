#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, k, c);
  VEC(ll, a, n);
  FOR(i, n) a[i] -= c * i;
  sort(a, greater());
  ll ans = std::accumulate(a.begin(), a.begin() + k, 0ll);
  UL(ans + c * ((k - 1) * k / 2));
}
#include "MeIoN_Lib/Z_H/main.hpp"