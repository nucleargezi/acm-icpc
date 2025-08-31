#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/lpf_table.hpp"

#define tests
meion minp = lpf_table(5'000'001);
bool c[5'000'001];
vector<int> v;
void Yorisou() {
  v.resize(0);
  LL(n);
  VEC(int, a, n);
  if (n & 1) iroha YES();
  if (n == 2) iroha YES(a[0] == a[1]);
  for (int x : a) {
    while (x != 1) {
      int e = minp[x];
      v.emplace_back(e);
      while (x % e == 0) {
        x /= e, c[e] ^= 1;
      }
    }
  }
  unique(v);
  bool s = 0;
  for (int x : v) s |= c[x], c[x] = 0;
  YES(not s);
}
#include "MeIoN_Lib/Z_H/main.hpp"