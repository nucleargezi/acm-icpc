#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/SA.hpp"

// #define tests
void Yorisou() {
  S(s);
  const ll N = len(s);
  SA<0> sa(s);
  ll ans = N * (N + 1) / 2;
  ans -= SUM<ll>(sa.lcp);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"