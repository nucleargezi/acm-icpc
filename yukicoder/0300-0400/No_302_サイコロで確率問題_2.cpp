#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
re bf(ll N, ll l, ll r) {
  chmax(l, 0);
  chmin(l, 6 * N);
  chmax(r, 0);
  chmin(r, 6 * N);
  vc<re> dp(6 * N + 1);
  dp[0] = 1;
  FOR(i, N) {
    FOR_R(k, 6 * i + 1) {
      FOR(j, 1, 7) dp[k + j] += dp[k] / 6;
      dp[k] = 0;
    }
  }
  re s = 0;
  FOR(i, l, r + 1) s += dp[i];
  return s;
}
re f(re r) { return (1 + erf(r / sqrtl(2.l))) / 2.l; }
void Yorisou() {
  setp(20);
  LL(N, l, r);
  if (N <= 5000) return print(bf(N, l, r));
  re s = sqrtl(35 * N / 12.l);
  print(f((r + 0.5 - 3.5 * N) / s) - f((l - 0.5 - 3.5 * N) / s));
}

int main() {
  Yorisou();
  return 0;
}