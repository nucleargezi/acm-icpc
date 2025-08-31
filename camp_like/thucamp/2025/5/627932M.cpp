#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"


#define tests
meion pr = primtable(4000);
void Yorisou() {
  LL(n);
  vector<int> factor;
  for (int i : pr) {
    if (n == 1) break;
    while (n % i == 0) {
      factor.emplace_back(i);
      n /= i;
    }
    if ((int)factor.size() > 1 and factor[0] * factor[1] < 4000) iroha UL(0);
  }
  UL(n < 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"