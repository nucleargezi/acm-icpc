#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, fa, n - 1);
  vector<ll> ans(n);
  FOR(i, n - 1) ++ans[fa[i] - 1];
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"