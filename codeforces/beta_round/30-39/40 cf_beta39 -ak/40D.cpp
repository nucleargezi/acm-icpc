#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/bigint/bigint.hpp"

// #define tests
using L = BigInteger;
void Yorisou() {
  L a;
  IN(a);
  vector<L> pow;
  pow.emplace_back(1);
  while (pow.back() <= a) pow.emplace_back(pow.back() * 12);
  pop(pow);
  ll n = len(pow);
  FOR(i, n) FOR(k, i + 1) {
    if (pow[i] + pow[k] != a) continue;
    YES();
    UL(1);
    UL(1 + i + k);
    ll n = i + k;
    while (len(pow) <= n) pow.emplace_back(pow.back() * 12);
    vector<L> ans;
    FOR(i, n + 1) {
      ll k = n - i;
      if (i <= k) {
        L x = pow[i] + pow[k];
        if (x == a) continue;
        ans.emplace_back(x);
      }
    }
    sort(ans);
    UL(len(ans));
    FOR(i, len(ans)) UL(ans[i]);
    iroha;
  }
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"