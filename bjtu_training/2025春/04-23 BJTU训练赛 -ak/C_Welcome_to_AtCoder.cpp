#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<u8> vis(n);
  vector<ll> c(n);
  ll a = 0, b = 0;
  FOR(m) {
    LL(x);
    S(state);
    --x;
    if (state == "AC") {
      a += not vis[x];
      vis[x] = 1;
    } else {
      c[x] += not vis[x];
    }
  }
  FOR(i, n) b += vis[i] * c[i];
  UL(a, b);
}
#include "MeIoN_Lib/Z_H/main.hpp"