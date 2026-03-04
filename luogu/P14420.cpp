#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/ds/mo/mo_roll.hpp"
#include "YRS/ds/rb/rb_arr.hpp"

void Yorisou() {
  INT(N, Q);
  vc<PII> a(N);
  vc<int> f(N);
  FOR(i, N) IN(a[i].se), f.ep(a[i].se);
  unique(f);
  for (Z &[x, y] : a) x = lb(f, y);
  rb_arr<int> c(len(f));
  mo_rollback mo(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    mo.add(l, r);
  }
  ll mx = 0, cp;
  vc<ll> ans(Q);
  Z ad = [&](int i) {
    Z [x, rx] = a[i];
    ll cnt = c[x] + 1;
    c.set(x, cnt);
    chmax(mx, cnt * rx);
  };
  int t;
  Z reset = [&]() { mx = 0, c.reset(); };
  Z save = [&]() { t = c.time(), cp = mx; };
  Z rb = [&]() { mx = cp, c.rb(t); };
  Z get = [&](int i) { ans[i] = mx; };
  mo.f(ad, ad, reset, save, rb, get);
  for (ll x : ans) print(x);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"