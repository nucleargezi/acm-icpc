#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m, a, b, c);
  if (n & m & 1) iroha IMPOSSIBLE();
  vector s(n, string(m, ' '));
  if (n & 1) {
    FOR(i, 0, m - 1, 2) {
      if (not a--) iroha IMPOSSIBLE();
      s[n - 1][i] = s[n - 1][i + 1] = 'a' + (n + i) % 26;
    }
  } else if (m & 1) {
    FOR(i, 0, n - 1, 2) {
      if (not b--) iroha IMPOSSIBLE();
      s[i][m - 1] = s[i + 1][m - 1] = 'a' + (m + i) % 26;
    }
  }
  n -= n & 1, m -= m & 1;
  FOR(i, 0, n, 2) {
    FOR(k, 0, m, 2) {
      if (c) {
        --c;
        FOR(x, 2) FOR(y, 2) s[i + x][k + y] = 'a' + (i + k + 1) % 26;
      } else if (a > 1) {
        a -= 2;
        FOR(x, 2) FOR(y, 2) s[i + x][k + y] = 'a' + (i + k + x) % 26;
      } else if (b > 1) {
        b -= 2;
        FOR(x, 2) FOR(y, 2) s[i + x][k + y] = 'a' + (i + k + y) % 26;
      } else {
        iroha IMPOSSIBLE();
      }
    }
  }
  for (meion &s : s) UL(s);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}