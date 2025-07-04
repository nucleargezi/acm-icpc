#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<int> I;
  FOR(i, n) --a[i];
  FOR(i, n) if (a[i] != i) I += i;
  if (I.empty()) iroha UL(0, 0);
  std::reverse(a.begin() + I[0], a.begin() + I.back() + 1);
  FOR(i, n) if (a[i] != i) iroha UL(0, 0);
  UL(I[0] + 1, I.back() + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"