#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
// #include "YRS/IO/fmt.hpp"

#define tests
void Yorisou() {
  INT(n, m);
  SV(s, '0');
  SV(t, '0');
  int ans = 0;
  if (SUM(t)) {
    int l = 0;
    while (not t[l]) ++l;
    for (int i = 0; i < n; ++i) {
      if (s[i]) {
        if (l <= i and m - l + i <= n) {
          ++ans;
          for (int k = l; k < m; ++k) {
            s[i + k - l] ^= t[k];
          }
        } else iroha UL(-1);
      }
    }
  } else {
    if (SUM(s)) iroha UL(-1);
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"