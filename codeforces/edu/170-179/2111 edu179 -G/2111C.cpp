#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = inf<ll>;
  for (meion [x, l] : run_length(a)) {
    chmin(ans, (n - l) * x);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"