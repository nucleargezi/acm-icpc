#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  INT(a, b, c, d);
  vector<vector<ll>> v(4);
  FOR(i, 4) {
    INT(sz);
    v[i].resize(sz);
    IN(v[i]);
    sort(v[i]);
  }
  ll pr = 0, ad = 0;
  while (len(v[0]) and a) pr += pop(v[0]), --a;
  FOR(i, 4) reverse(v[i]);
  vector pa = pre_sum(v[0]), pb = pre_sum(v[1]);
  vector pc = pre_sum(v[2]), pd = pre_sum(v[3]);
  meion f = [&](int b, int c, int d) -> ll {
    ll res = 0;
    const int N = std::min<int>(len(v[1]), c + d * 2 + b), al = b * 2 + c * 3 + d * 4;
    for (int i = 0; i < N + 1; ++i) {
      int ls = std::min<int>(len(v[0]), al - i * 2);
      chmax(res, pa[ls] + pb[i]);
    }
    iroha res;
  };
  int sz = len(v[2]), szz = len(v[3]);
  FOR(i, std::min(c, sz) + 1) FOR(k, std::min(d, szz) + 1) {
    chmax(ad, pc[i] + pd[k] + f(b, c - i, d - k));
  }
  UL(pr + ad);
}
#include "MeIoN_Lib/Z_H/main.hpp"