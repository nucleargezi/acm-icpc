#include "YRS/all.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  ll a, b;
  while (cin >> a >> b) {
    ll mx = inf<ll>, l{}, r{};
    Z fac = factor(b);
    int n = si(fac);
    vc<ll> ls(n), rs(n);
    FOR(i, n) {
      ll s = 1, e = fac[i].fi;
      while (a % e == 0) a /= e, s *= e;
      ls[i] = s;
      s = 1;
      FOR(k, fac[i].se) s *= e;
      rs[i] = s;
    }
    FOR(s, 1 << n) {
      ll x = 1, y = 1;
      FOR(i, n) {
        if (s >> i & 1) x *= ls[i], y *= rs[i];
        else x *= rs[i], y *= ls[i];
      }
      if (x > y) swap(x, y);
      if (chmin(mx, x + y)) l = x, r = y;
    }
    print(l, r);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}