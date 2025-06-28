#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  vector v(n, vector<ll>(n, inf<ll> / 4));
  FOR(i, n) v[i][i] = 0;
  FOR(m) {
    LL(x, y, w);
    --x, --y;
    swap(x, y);
    chmin(v[x][y], w);
  }
  meion d = v;
  FOR(i, n) FOR(x, n) FOR(y, n) {
    chmin(d[x][y], d[x][i] + d[i][y]);
  }
  LL(q);
  FOR(q) {
    LL(K);
    VEC(ll, a, n);
    vector c(a);
    FOR(i, n) FOR(k, n) chmin(c[k], a[i] + v[i][k]);
    string ans(n, '0');
    vector<ll> t(n, inf<ll> / 4);
    FOR(i, n) FOR(k, n) if (v[i][k] != d[i][k]) {
      chmin(t[k], a[i] - (c[k] - d[i][k] - 1));;
    }
    FOR(i, n) ans[i] += K >= t[i];
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"