#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  S(s);
  FOR(q) {
    S(t);
    LL(a);
    ll m = len(t);
    string go;
    FOR(i, m) {
      go += t[i] == s[i + a - 1];
    }
    ll ans = 0;
    for (meion [x, y] : run_length(go)) {
      if (x) ans += y * (y + 1) / 2;
    }
    print("{}", ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"