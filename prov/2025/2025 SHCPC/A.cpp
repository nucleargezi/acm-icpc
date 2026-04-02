#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  LL(x);
  static ll a[114514];
  ll se;
  Z f = [&](Z &f, ll p, ll ls, ll c, ll s) -> void {
    if (s > x) return;
    if (not c) {
      if (s == x) {
        Yes();
        vector<int> ans;
        FOR(i, p) {
          FOR(a[i]) ans.ep(i + 1);
        }
        print(len(ans));
        print(ans);
        exit(0);
      }
      return;
    }
    FOR(i, ls, c + 1) {
      a[p] = i;
      f(f, p + 1, i, c - i, s + (1ll << se) - (1ll << (se - i)));
    }
  };
  FOR(i, 60) se = i + 1, f(f, 0, 1, i + 1, 0);
  No();
}
#include "YRS/Z_H/main.hpp"