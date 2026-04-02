#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/min.hpp"
#include "YRS/ds/sparse_table/st.hpp"

// #define tests
void Yorisou() {
  INT(Q, N);
  constexpr int sz = 1'000'000 + 10;
  vector<ll> g(sz);
  FOR(i, N) {
    INT(x, y);
    chmax(g[x], y);
  }
  vector<ll> dat(sz, inf<ll>);
  FOR(i, 1, sz) FOR(k, sz / i + 1) if (k * i < sz) 
    chmin(dat[k * i], k * (i - g[i]));
  FOR(i, 1, sz) chmin(dat[i], dat[i - 1] + 1);
  ST<monoid_min<ll>> seg(dat);
  
  FOR(Q) {
    LL(w, p, q);
    ll x = w * p / q;
    ll ans = x < w ? seg.prod(x + 1, w + 1) : dat[w];
    if (dat[x] < ans) {
      ll a = (dat[x] - x) * q + w * p, b = q;
      ll g = std::gcd(a, b);
      a /= g, b /= g;
      print(a, b);
    } else print(ans, 1);
  }
}
#include "YRS/Z_H/main.hpp"