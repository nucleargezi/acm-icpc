#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
using T = array<array<mint, 3>, 3>;
void Yorisou() {
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] = s[i] == '(';
  vc<int> pr(all(s));
  FOR(i, N) if (pr[i] == 0) pr[i] = -1;
  pr = pre_sum(pr);
  
  retsu<T> dp(N, N + 1);
  FOR_R(l, N) if (s[l]) FOR(r, l + 2, N + 1, 2) if (not s[r - 1]) {
    if (pr[r] != pr[l]) continue;
    Z &x = dp[l][r];
    if (r - l == 2) {
      x[0][1] = x[0][2] = x[1][0] = x[2][0] = 1;
    } else {
      var y = dp[l + 1][r - 1];
      for (Z [a, d] : {PII{0, 1}, {0, 2}, {1, 0}, {2, 0}}) {
        FOR(b, 3) if (b != a or (not a and not b)) {
          FOR(c, 3) if (c != d or (not c and not d)) {
            x[a][d] += y[b][c];
          }
        }
      }
    }

    FOR(m, l + 2, r - 1, 2) if (pr[m] == pr[l]) {
      Z ls = dp[l][m], rs = dp[m][r];
      FOR(c, 3) FOR(d, 3) if (c != d or (not c and not d)) {
        FOR(l, 3) FOR(e, 3) {
          x[l][e] += ls[l][c] * rs[d][e];
        }
      }
      break;
    }
  }
  mint rs;
  FOR(i, 3) FOR(k, 3) rs += dp[0][N][i][k];
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}