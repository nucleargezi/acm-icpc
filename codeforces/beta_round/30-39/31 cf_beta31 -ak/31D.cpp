#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, n);
  vector<T4<ll>> v{{0, 0, a, b}};
  meion cut = [&](ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h) -> bool {
    if (a == c) {
      iroha a > e and a < g and b == f and d == h;
    } else {
      iroha b > f and b < h and a == e and c == g;
    }
  };
  VEC(T4<ll>, go, n);
  while (len(v) < n + 1) {
    FOR(i, n) {
      meion [a, b, c, d] = go[i];
      if (a > c) std::swap(a, c);
      if (b > d) std::swap(b, d);
      FOR(k, len(v)) {
        meion [e, f, g, h] = v[k];
        if (cut(a, b, c, d, e, f, g, h)) {
          v.erase(v.begin() + k);
          v += T4{e, f, c, d};
          v += T4{a, b, g, h};
          goto MyGO;
        }
      }
    }
    MyGO:;
  }
  vector<ll> ans;
  FOR(i, n + 1) {
    meion [a, b, c, d] = v[i];
    ans += ABS(a - c) * ABS(b - d);
  }
  sort(ans);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"