#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
using RE = long double;
constexpr ll in = 1'000'000'000'000'000'000ll;
inline RE pw(RE a, ll k) {
  RE r = 1;
  FOR(k) r *= a;
  return r;
}
void Yorisou() {
  INT(N, L, P);
  VEC(string, s, N);
  vc<int> c(N);
  FOR(i, N) c[i] = len(s[i]);
  c = pre_sum(c);
  FOR(i, N) c[i + 1] += i + 1;
  vc<RE> dp(N + 1, -1);
  vc<int> fa(N + 1, -1);
  dp[0] = 0;
  Z f = [&](Z &f, int l, int r, int ql, int qr) -> void {
    if (l > r) return;
    int m = (l + r) >> 1, id = ql, nr = min(qr, m - 1);
    RE e = -1;
    FOR(k, ql, nr + 1) {
      RE nx = dp[k] + pw(std::abs(c[m] - c[k] - 1 - L), P);
      if (e == -1 or e > nx) e = nx, id = k;
    }
    if (dp[m] == -1 or e < dp[m]) dp[m] = e, fa[m] = id;
    f(f, l, m - 1, ql, id), f(f, m + 1, r, id, qr);
  };
  Z y = [&](Z &y, int l, int r) -> void {
    if (l == r) return;
    int m = (l + r) >> 1;
    y(y, l, m);
    f(f, m + 1, r, l, m);
    y(y, m + 1, r);
  };
  y(y, 0, N);
  if (dp[N] > in) {
    print("Too hard to arrange");
  } else {
    print((ll)dp[N]);
    vc<string> ans;
    int x = N;
    while (fa[x] != -1) {
      string str;
      FOR(i, fa[x], x) {
        str += s[i];
        str += ' ';
      }
      pop(str);
      ans.ep(str);
      x = fa[x];
    }
    reverse(ans);
    for (Z &s : ans) print(s);
  }
  print("--------------------");
}
#include "YRS/Z_H/main.hpp"