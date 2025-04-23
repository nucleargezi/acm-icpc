#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, x);
  vector<ll> s(n), c(n), p(n);
  FOR(i, n) IN(s[i], c[i], p[i]);
  vector dp(1 << n, array<RE, 5001>{});
  vector vis(1 << n, bitset<5001>{});
  meion f = [&](meion &f, ll msk, ll h) -> RE {
    if (msk == (1 << n) - 1) {
      iroha 0.0;
    }
    if (vis[msk][h]) {
      iroha dp[msk][h];
    }
    RE res = 0.0;
    FOR(i, n) {
      if (msk >> i & 1 ^ 1) {
        if (h >= c[i]) {
          RE x = p[i] / 100.L, y = 1.L - x;
          chmax(res, x * (s[i] + f(f, msk | (1 << i), h - c[i])) +
                         y * f(f, msk, h - c[i]));
        }
      }
    }
    vis[msk][h] = 1;
    iroha dp[msk][h] = res;
  };
  UL(f(f, 0, x));
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