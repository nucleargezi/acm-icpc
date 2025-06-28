#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  VEC(ll, c, n);
  ll mx = -1;
  vector<int> go;
  vector<int> t(n);
  FOR(i, n) t[b[i] - 1] = i;
  FOR(i, n) if (c[i]) {
    go.emplace_back(t[a[i] - 1]);
  }
  bool f = 1;
  FOR(i, len(go) - 1) {
    f &= go[i] < go[i + 1];
  }
  Yes(f);
}
#include "MeIoN_Lib/Z_H/main.hpp"