#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/K_cdq.hpp"

// #define tests
void Yorisou() {
  LL(n, k);
  vector<array<int,3>> a(n);
  IN(a);
  K_cdq<int, 3> g(a);
  meion res = g.keis();
  vector<int> ans(n);
  for (int x : res) ans[x]++;
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"