#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"

// #define tests
using A = retsu<int>;
void Yorisou() {
  INT(N, M);
  A a(N, M);
  FOR(i, N) FOR(k, M) {
    CH(c);
    a[i][k] = c == '#';
  }

  Z f = [&](A a) -> int {
    vector<int> g;
    FOR(k, M) FOR(i, N) if (a[i][k]) {
      int x = i, y = k;
      while (x + 1 < N and a[x + 1][y]) ++x;
      while (y + 1 < M) {
        int t = y + 1;
        bool ok = 1;
        FOR(j, x - i + 1) ok &= a[i + j][t];
        if (ok) ++y;
        else break;
      }
      int c = std::min(x - i, y - k) + 1;
      g.ep(c);
      FOR(j, c) FOR(l, c) a[i + j][k + l] = 0;
    }
    int ans = 0;
    for (int x : g) ans = std::gcd(ans, x);
    return ans;
  };
  Z ff = [&](A a) -> int {
    vector<int> g;
    FOR(i, N) FOR(k, M) if (a[i][k]) {
      int x = i, y = k;
      while (x + 1 < N and a[x + 1][y]) ++x;
      while (y + 1 < M) {
        int t = y + 1;
        bool ok = 1;
        FOR(j, x - i + 1) ok &= a[i + j][t];
        if (ok) ++y;
        else break;
      }
      int c = std::min(x - i, y - k) + 1;
      g.ep(c);
      FOR(j, c) FOR(l, c) a[i + j][k + l] = 0;
    }
    int ans = 0;
    for (int x : g) ans = std::gcd(ans, x);
    return ans;
  };
  int ans = std::max(f(a), ff(a));
  Z check = [&](A a, int c) -> bool {
    FOR(i, N - c + 1) FOR(k, M - c + 1) if (a[i][k] == 1) {
      FOR(x, c) FOR(y, c) --a[i + x][k + y];
    } else if (a[i][k] < 0) return false;
    FOR(i, N) FOR(k, M) if (a[i][k] != 0) return false;
    return true;
  };
  FOR(i, ans + 1, 40) {
    if (check(a, i)) ans = i;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"