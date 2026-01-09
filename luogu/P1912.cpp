#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
using re = long double;
constexpr ll in = 1'000'000'000'000'000'000ll;
inline re pw(re a, ll k) {
  re r = 1;
  FOR(k) r *= a;
  return r;
}
template <typename T>
Z monge_dp(int N, const Z &w) {
  vc<T> dp(N + 1, inf<T> / 2);
  vc<int> x(N + 1, 0);
  Z upd = [&](int l, int r) {
    if (l >= r) return;
    if (chmin(dp[r], dp[l] + w(l, r))) x[r] = l;
  };
  Z f = [&](Z f, int l, int r) -> void {
    if (l + 1 >= r) return;
    int m = (l + r) >> 1;
    FOR(i, x[l], x[r] + 1) upd(i, m);
    f(f, l, m);
    FOR(i, l, m) upd(i + 1, r);
    f(f, m, r);
  };
  dp[0] = 0, upd(0, N), f(f, 0, N);
  return pair{dp, x};
}
void Yorisou() {
  INT(N, L, P);
  VEC(string, s, N);
  vc<int> c(N);
  FOR(i, N) c[i] = len(s[i]);
  c = pre_sum(c);
  FOR(i, N) c[i + 1] += i + 1;
  Z w = [&](int l, int r) -> re {
    return pw(std::abs(c[r] - c[l] - 1 - L), P);
  };
  Z [dp, fa] = monge_dp<re>(N, w);
  if (dp[N] > in) {
    print("Too hard to arrange");
  } else {
    print((ll)dp[N]);
    vc<string> ans;
    int x = N;
    while (fa[x] != -1 and fa[x] != x) {
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
#include "YRS/aa/main.hpp"