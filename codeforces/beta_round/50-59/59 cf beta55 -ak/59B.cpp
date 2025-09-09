#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(n);
  vector<int> a;
  ll ans = 0;
  FOR(i, n) {
    INT(x);
    if (x & 1) a.emplace_back(x);
    else ans += x;
  }
  sort(a, greater());
  if (not(len(a) & 1) and len(a)) pop(a);
  ans += SUM(a);
  if (not(ans & 1)) ans = 0;
  UL(ans);
}
#include "YRS/Z_H/main.hpp"