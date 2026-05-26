#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, c, d);
  VEC(T4<int>, a, M);
  vc<ll> dp(N + 1);
  for (var [a, b, c, d] : a) {
    int t = min(a / b, N / c);
    FOR(t) FOR_R(i, c, N + 1) {
      chmax(dp[i], dp[i - c] + d);
    }
  }
  ll s = 0;
  FOR(i, N + 1) chmax(s, dp[i] + (N - i) / c * d);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}