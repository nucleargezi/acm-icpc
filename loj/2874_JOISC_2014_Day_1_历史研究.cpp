#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/mo/mo_roll.hpp"
#include "YRS/ds/rb/rb_arr.hpp"

void Yorisou() {
  INT(N, Q);
  vc<PII> a(N);
  vc<int> f(N);
  FOR(i, N) IN(a[i].se), f.ep(a[i].se);
  unique(f);
  for (Z &[x, y] : a) x = lb(f, y);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  rb_arr<int> c(si(f));
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
  mo_roll(q, ad, ad, reset, save, rb, get);
  for (ll x : ans) print(x);
}

int main() {
  Yorisou();
  return 0;
}