#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  LL(W);
  vc<vc<int>> v;
  vc<ll> c;
  Z ge = [&](Z &ge, int n, int f) -> void {
    if (f != -1) v[f].ep(n);
    INT(w, sz);
    v.ep();
    c.ep(w);
    v[n].reserve(sz);
    FOR(sz) ge(ge, len(c), n);
  };
  ge(ge, 0, -1);
  ll ans = 0;
  Z f = [&](Z &f, int n) -> ll {
    vc<ll> s;
    for (int x : v[n]) {
      ll nx = f(f, x);
      if (nx != 0) s.ep(nx);
    }
    sort(s);
    ll sm = SUM(s);
    while (sm >= W) sm -= pop(s), ++ans;
    c[n] += sm;
    ans += c[n] / W;
    c[n] %= W;
    return c[n];
  };
  ll s = f(f, 0);
  print(ans + ceil(s, W));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"