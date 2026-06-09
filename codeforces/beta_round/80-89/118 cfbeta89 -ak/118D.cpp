#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = mint_t<1'000'000'00>;
mint f[101][101][11][11];
void Yorisou() {
  INT(n, nn, K, KK);
  FOR(i, n + 1) FOR(k, nn + 1) if (i or k) {
    if (i + k == 1) {
      f[i][k][i][k] = 1;
      continue;
    }
    if (i) FOR(j, 2, K + 1) f[i][k][j][0] += f[i - 1][k][j - 1][0];
    if (k) FOR(j, 2, KK + 1) f[i][k][0][j] += f[i][k - 1][0][j - 1];
    if (k) FOR(j, 1, K + 1) f[i][k][0][1] += f[i][k - 1][j][0];
    if (i) FOR(j, 1, KK + 1) f[i][k][1][0] += f[i - 1][k][0][j];
  }
  mint s;
  FOR(i, K + 1) FOR(k, KK + 1) s += f[n][nn][i][k];
  print(s);
}

int main() {
  Yorisou();
  return 0;
}