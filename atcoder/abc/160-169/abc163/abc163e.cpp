#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z I = argsort(a);
  reverse(I);
  retsu<ll> dp(N + 1, N + 1, ine<ll> / 2);
  dp[0][0] = 0;
  FOR(i, N) {
    int id = I[i];
    FOR(l, i + 1) {
      int r = i - l;
      chmax(dp[i + 1][l + 1], dp[i][l] + ll(id - l) * a[id]);
      chmax(dp[i + 1][l], dp[i][l] + ll(N - r - 1 - id) * a[id]);
    }
  }
  ll s = 0;
  FOR(i, N + 1) chmax(s, dp[N][i]);
  print(s);
}

int main() { Yorisou(); }