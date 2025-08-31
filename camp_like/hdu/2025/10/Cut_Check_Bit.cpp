#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/bit_vec.hpp"

using bs = vector<uint>;
#define tests
void Yorisou() {
  int n, m;
  string s;
  IN(n, m, s);
  const int N = ceil(m, 6);
  bs X(N);
  meion f = [&](bs &X) -> void {
    std::fill(X.begin(), X.end(), 0);
    reverse(s);
    for (int t = 0; char c : s) {
      uint x = 0;
      if ('a' <= c and c <= 'z') {
        x = c - 'a' + 10;
      } else {
        x = c - '0';
      }
      int i = t / 6, k = t % 6;
      t++;
      X[i] |= x << (5 * k);
    }
  };
  meion AND = [&](const bs &Y, bs &rui) -> void {
    for (int i = 0; i < N; ++i) {
      rui[i] &= Y[i];
    }
  };
  meion cmp = [&](const bs &a, const bs &b) -> bool {
    for (int i = N; i--; ) {
      if (a[i] < b[i]) iroha true;
      else if (a[i] > b[i]) iroha false;
    }
    iroha true;
  };
  f(X);
  vector a(n, bs(N));
  bs rui(N, -1);
  for (int i = 0; i < n; ++i) {
    IN(s);
    f(a[i]);
    AND(a[i], rui);
  }
  if (not cmp(rui, X)) {
    iroha UL(-1);
  }
  bit_vec bit(n);
  vector<pair<int, int>> seg;
  vector<int> go(n), tg(n), dp(n + 1);
  for (int i = 0; i < n; ++i) go[i] = i + 1;

  int ans = 0;
  meion DP = [&]() -> void {
    std::fill(dp.begin(), dp.end(), 0);
    for (int i = 0; i < n; ++i) {
      if (i) chmax(dp[i], dp[i - 1]);
      if (tg[i]) {
        chmax(dp[tg[i]], dp[i] + 1);
      }
    }
    chmax(ans, QMAX(dp));
  };

  for (int i = N; i--; ) {
    for (int k = 30; k--; ) {
      bit.reset();
      seg.clear();
      bool one = X[i] >> k & 1;
      for (int j = 0; j < n; ++j) {
        bit[j] = (a[j][i] >> k & 1) ^ 1;
      }
      int pr = -1;
      for (int i = bit._Find_first(); i < n; i = bit._Find_next(i)) {
        seg.emplace_back(pr + 1, i);
        pr = i;
      }
      seg.emplace_back(pr + 1, n);
      for (int i = 0; i < n; ++i) tg[i] = i + 1;
      for (meion [l, r] : seg) {
        for (int i = l; i < r; ++i) {
          tg[i] = r + 1;
        }
      }
      for (int i = 0; i < n; ++i) {
        chmax(tg[i], go[i]);
      }
      if (one) {
        DP();
      } else {
        go.swap(tg);
      }
    }
  }
  swap(tg, go);
  DP();
  UL(ans);
}
#include "YRS/Z_H/main.hpp"