#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using bs = bitset<18>;
void Yorisou() {
  LL(n, m);
  vector<bs> s(m, bs{});
  FOR(i, m) {
    S(x);
    FOR(k, n) s[i][k] = x[k] == '1';
  }
  LL(a, b, c);
  --a, --b, --c;
  LL(d, e, f);
  FOR(msk, 1 << n) if (popcount(msk) <= 13 and popcount(msk) >= 10) {
    bs M = bs(msk);
    vector<int> x;
    FOR(i, m) {
      x += (M & s[i]).count();
    }
    sort(x, greater());
    if (x[a] == d and x[b] == e and x[c] == f) {
      vector<int> ans;
      FOR(i, n) if (M[i]) ans += i + 1;
      UL(popcount(msk));
      UL(ans);
      iroha;
    }
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"