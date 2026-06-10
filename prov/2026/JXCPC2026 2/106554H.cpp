#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = array<ll, 3>;
void Yorisou() {
  INT(N, M, A, B);
  VEC(T, a, N);
  ll rs = -1;
  int pr = -1;
  T dp{};
  FOR(i, 1 << N) {
    int s = i ^ (i >> 1);
    if (pr == -1) {
      FOR(k, N) if (s >> k & 1) FOR(j, 3) dp[j] += a[k][j];
    } else {
      int k = lowbit(pr ^ s);
      if (pr < s) FOR(j, 3) dp[j] += a[k][j];
      else FOR(j, 3) dp[j] -= a[k][j];
    }
    if (dp[2] <= M and s and dp[0] * B == dp[1] * A) chmax(rs, dp[0]);
    pr = s;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}