#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"
#include "MeIoN_Lib/math/mod/modint61.hpp"

void before() {}

// #define tests
using m61 = modint61;
void Yorisou() {
  LL(n, K, q);
  S(s);
  for (char &c : s) c -= 'a';
  vector c(26, vector<int>(n));
  FOR(i, n) c[s[i]][i] = 1;
  FOR(i, 26) c[i] = pre_sum(c[i]);
  hash_map<ll> M;
  vector<int> V(n + 1);
  int tot = 0;
  FOR(i, n + 1) {
    m61 s = 0;
    FOR(k, 26) {
      s = s * 1000000123 + c[k][i] % K;
    }
    if (not M.contains(s.val)) M[s.val] = tot++;
    V[i] = M[s.val];
  }

  Mo mo;
  vector<int> T(tot + 1);
  FOR(q) {
    LL(l, r);
    mo.add(--l, ++r);
  }
  ll res = 0;
  vector<ll> ans(q);
  meion ad = [&](int i) -> void {
    res += T[V[i]]++;
  };
  meion rm = [&](int i) -> void {
    res -= --T[V[i]];
  };
  meion keisan = [&](int i) -> void {
    ans[i] = res;
  };
  mo.keisan(ad, ad, rm, rm, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"