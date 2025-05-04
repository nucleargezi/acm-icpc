#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  ll n = len(s);
  vector<ll> c(n + 1);
  LL(q);
  FOR(i, q) {
    LL(x);
    ++c[--x];
    --c[n - x];
  }
  c = pre_sum<false>(c);
  FOR(i, n >> 1) if (c[i] & 1) std::swap(s[i], s[n - i - 1]);
  UL(s);
}
#include "MeIoN_Lib/Z_H/main.hpp"