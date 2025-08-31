#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using mint = M99;
meion pw = power_table_1(mint(2), 5'000'00);
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  mint ans;
  int c = std::ranges::count(a, -1);
  FOR(i, n) {
    if (not i) {
      if (a[i]) ans += pw[c - (a[i] == -1)];
    } else {
      if (not a[i] or a[i - 1] == 1) continue;
      ans += pw[c - (a[i] == -1) - (a[i - 1] == -1)];
    }
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"