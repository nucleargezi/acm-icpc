#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/st/st_range_prod.hpp"
#include "YRS/al/m/gcd.hpp"

void Yorisou() {
  INT(N);
  constexpr int sz = 5'000'00 + 1;
  vc<ll> a(sz);
  FOR(N) {
    INT(x);
    LL(v);
    a[x] = gcd(a[x], v);
  }
  ll s = 0;
  FOR(i, sz) s = gcd(a[i], s);
  st_range_prod_t<monoid_gcd<ll>, 1, 6> st(a);
  FOR_R(i, s + 1, sz) {
    ll t = i;
    FOR(k, 1, sz, i) {
      t = gcd(t, st.prod(k, min(sz, k + i - 1)));
      if (t <= s) break;
    }
    chmax(s, t);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"