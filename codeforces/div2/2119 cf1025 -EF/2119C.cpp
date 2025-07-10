#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, l, r, k);
  ll ans = -1;
  if (n & 1) {
    ans = l;
  } else if (n != 2 and (1ll << (topbit(l) + 1)) <= r) {
    ans = (k <= n - 2) ? l : (1ll << (topbit(l) + 1));
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"