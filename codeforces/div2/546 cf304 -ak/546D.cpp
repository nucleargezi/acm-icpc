#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"

ll c[5'000'001];

void before() {
  for (ll p : primtable(5'000'000)) {
    ll x = p;
    while (x < 5'000'001) {
      ll g = x;
      while (g < 5'000'001) {
        ++c[g];
        g += x;
      }
      x *= p;
    }
  }
  FOR(i, 5'000'000) c[i + 1] += c[i];
}

#define tests
void Yorisou() {
  LL(a, b);
  UL(c[a] - c[b]);
}
#include "MeIoN_Lib/Z_H/main.hpp"