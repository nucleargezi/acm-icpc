#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

TE Z monge_dp_N(int N, var w) {
  vc<T> dp(N + 1, inf<T> / 2);
  vc<int> s(N + 1, 0);
  Z g = [&](int l, int r) {
    if (l >= r) return;
    if (chmin(dp[r], dp[l] + w(l, r))) s[r] = l;
  };
  Z f = [&](Z &f, int l, int r) -> void {
    if (l + 1 >= r) return;
    int m = (l + r) >> 1;
    FOR(i, s[l], s[r] + 1) g(i, m);
    f(f, l, m);
    FOR(i, l, m) g(i + 1, r);
    f(f, m, r);
  };
  dp[0] = 0, g(0, N), f(f, 0, N);
  return dp;
}

void Yorisou() {
  INT(N);
  vc<i128> x(N), p(N), c(N);
  FOR(i, N) IN(x[i], p[i], c[i]);
  
  Z sxp = x;
  FOR(i, N) sxp[i] *= p[i];
  sxp = pre_sum(sxp);
  p = pre_sum(p);
  Z f = monge_dp_N<i128>(N, [&](int l, int r) {
    return x[r - 1] * (p[r] - p[l]) - (sxp[r] - sxp[l]) + c[r - 1];
  });
  i128 rs = f[N];
  FOR_R(i, N) {
    if (p[i + 1] - p[i] == 0) chmin(rs, f[i]);
    else break;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}