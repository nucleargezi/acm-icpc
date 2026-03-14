#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"
#include "YRS/string/SA.hpp"

// #define tests
void Yorisou() {
  STR(s);
  const ll N = len(s);
  SA<0> sa(s);
  ll ans = N * (N + 1) / 2;
  ans -= SUM<ll>(sa.lcp);
  print("{}", ans);
}
#include "YRS/Z_H/main.hpp"