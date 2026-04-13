#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
re f(int N, re t) {
  vc<re> dp(N + 1);
  FOR(i, 1, N + 1) {
    FOR(k, 1, 7) {
      if (k > i) dp[i] += t / 6;
      else dp[i] += dp[i - k] / 6;
    }
    dp[i] += 1;
  }
  return dp[N];
}
re f(int N) {
  return bina_real<re>([&](re t) { return f(N, t) <= t; }, inf<int>, 0);
}

void Yorisou() {
  setp(20);
  LL(N);
  if (N <= 300) print(f(N));
  else print(N + re(5) / 3);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}