#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  SV(a, '0');
  int ans = n / 2;
  meion f = [&](int x) {
    vector<int> vis(n);
    FOR(i, n) {
      if (a[i] == (x ^ (i & 1))) continue;
      vis[i] = 1;
    }
    int c = SUM(vis);
    if (c == 0 or c == n) {
      chmin(ans, c / 2);
      iroha;
    }
    int I = 0;
    while (I < n and vis[I]) ++I;
    int al = 0, s = 0;
    FOR(i, n) {
      int p = (I + i + 1) % n;
      if (vis[p]) ++s;
      else al += s / 2, s = 0;
    }
    chmin(ans, c - al);
  };
  f(0), f(1);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"