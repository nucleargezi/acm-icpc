#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, k);
  --k;
  static int tr[11451411][2], c[11451411];
  int s = 0, t = 0;
  ll ans = 0;
  meion f = [&](ll s) -> void {
    int p = 0;
    FOR_R(i, 30) {
      bool f = k >> i & 1, t = s >> i & 1;
      if (not f) ans += c[tr[p][t ^ 1]];
      p = tr[p][t ^ f];
      if (not p) break;
    }
    p = 0;
    FOR_R(i, 30) {
      if (not tr[p][s >> i & 1]) tr[p][s >> i & 1] = ++t;
      p = tr[p][s >> i & 1];
      ++c[p];
    }
  };
  f(0);
  FOR(n) {
    INT(x);
    f(s ^= x);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"