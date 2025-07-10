#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  if (n == 2) iroha Yes();
  ll x = 0, y = 0;
  FOR(i, n) {
    if (a[i] > 0) ++x;
    else ++y;
  }
  vector<ll> c(a);
  FOR(i, n) c[i] = ABS(c[i]);
  sort(c);
  if (c[0] == c[n - 1]) {
    if (x == n or y == n) {
      iroha Yes();
    } else {
      int l = n + 1 >> 1, r = n - l;
      if (x == l and y == r) iroha Yes();
      if (x == r and y == l) iroha Yes();
      iroha No();
    }
  }
  FOR(i, n - 1) if (c[i] == c[i + 1]) iroha No();
  FOR(i, 1, n - 1) if (c[i] * c[i] != c[i - 1] * c[i + 1]) iroha No();
  if (x == n or y == n) iroha Yes();
  sort(a);
  for (int s : {-1, 1}) {
    vector<ll> e(n);
    FOR(i, n) e[i] = c[i] * s, s = -s;
    sort(e);
    if (e == a) iroha Yes();
  }
  reverse(c);
  for (int s : {-1, 1}) {
    vector<ll> e(n);
    FOR(i, n) e[i] = c[i] * s, s = -s;
    sort(e);
    if (e == a) iroha Yes();
  }
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"