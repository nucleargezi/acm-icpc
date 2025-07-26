#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  ll ans, x, y;
  ans = x = y = 0;
  FOR(i, n) {
    if (s[i]) {
      if (i and not s[i - 1]) x = y + 1;
      else x = 1;
      y = 0;
    } else {
      if (i) x += i;
      else x = 0;
      if (n - i - 1) y += n - i - 1;
      else y = 0;
    }
    chmax(ans, x), chmax(ans, y);
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"