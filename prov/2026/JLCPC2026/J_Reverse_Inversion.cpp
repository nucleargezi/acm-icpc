#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/inversion.hpp"

ll f(ll x) { return x * (x + 1) / 2; }

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  ll s = inversion(a), rs = s;
  Z dp = all_range_inversion(a);
  FOR(l, N) FOR(r, l, N) chmax(rs, s + f(r - l) - 2 * dp[l][r + 1]);
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}