#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  vector<PLL> val;
  FOR(i, n) {
    array<ll, 6> a;
    IN(a);
    sort(a);
    FOR(k, 6) val += PLL(a[k], i);
  }
  sort(val);
  vector<int> c(n);
  int cc = n;
  mint es = 1, iv[7];
  FOR(i, 1, 7) iv[i] = mint(i).inv();
  mint ans = 0, pr = 0;
  int N = len(val), id = 0;
  while (id < N) {
    int t = val[id].first;
    while (id < N and val[id].first == t) {
      int x = val[id].second, l = c[x], r = l + 1;
      c[x] = r;
      if (l == 0) {
        cc--;
        es *= r;
      } else {
        es *= iv[l] * r;
      }
      id++;
    }
    mint np = (cc > 0 ? 0 : es);
    ans += mint(t) * (np - pr);
    pr = np;
  }
  UL(ans * iv[6].pow(n));
}
#include "MeIoN_Lib/Z_H/main.hpp"