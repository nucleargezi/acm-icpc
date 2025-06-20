#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using bs = bitset<35>;
void Yorisou() {
  LL(sz, n);
  vector<bs> s(n);
  vector<int> c(n);
  FOR(i, n) {
    S(str);
    s[i] = bs(str);
    IN(c[i]);
  }
  ll ans = 0;
  vector<int> dif(n);
  meion ck = [&]() {
    FOR(i, n) if (dif[i] > c[i]) iroha false;
    iroha true;
  };
  meion f = [&](meion &f, int p) -> void {
    if (p == sz) {
      FOR(i, n) if (dif[i] != c[i]) iroha;
      ++ans;
      iroha;
    }
    FOR(x, 2) {
      FOR(i, n) dif[i] += s[i][p] != x;
      if (ck()) f(f, p + 1);
      FOR(i, n) dif[i] -= s[i][p] != x;
    }
  };
  f(f, 0);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"