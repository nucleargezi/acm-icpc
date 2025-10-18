#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint61.hpp"

// #define tests
using mint = M61;
void Yorisou() {
  INT(N, M);
  vector<mint> a(N + 1);
  FOR(i, N + 1) {
    mint x;
    STR(s);
    bool f = 0;
    if (s[0] == '-') f = 1, s.erase(0, 1);
    for (Z &c : s) c -= '0';
    for (int c : s) x = x * 10 + c;
    a[i] = f ? -x : x;
  }
  vector<int> ans;
  FOR(i, M + 1) {
    mint x = 1;
    mint s = 0;
    FOR(k, N + 1) {
      s += x * a[k];
      x *= i;
    }
    if (s == 0) ans.ep(i);
  }
  print(len(ans));
  for (int x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"