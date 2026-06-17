#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M, K);
  VEC(string, s, N);
  FOR(i, N) FOR(k, M) s[i][k] -= '0';
  retsu<int> re(N, M);
  static constexpr int dx[]{0, 1, 1, 1, 2}, dy[]{1, 0, 1, 2, 1};
  FOR(i, N - 2) FOR(k, M - 2) {
    bool ok = 1;
    FOR(d, 5) ok &= s[i + dx[d]][k + dy[d]];
    if (ok) re[i + 1][k + 1] = 1;
  }
  re.pres();
  ll rs = 0;
  FOR(l, N - 2) FOR(r, l + 1, N - 1) {
    int d = 0;
    FOR(c, M - 2) {
      chmax(d, c);
      while (d < M - 1 and re.prod(l, r, c, d) < K) ++d;
      rs += M - 1 - d;
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}