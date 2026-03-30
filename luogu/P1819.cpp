#include "YRS/all.hpp"
#include "YRS/string/subseq.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = mint_t<1'000'000'00>;
void Yorisou() {
  INT(N);
  string s[3];
  FOR(i, 3) IN(s[i]);
  FOR(i, 3) FOR(k, N) s[i][k] -= 'a';
  vc<array<int, 26>> nx[3];
  FOR(i, 3) nx[i] = subseq_next(s[i]);
  static mint f[151][151][151];
  FOR_R(i, N + 1) FOR(k, N + 1) FOR(j, N + 1) {
    mint s = 1;
    FOR(c, 26) {
      int p[3];
      p[0] = nx[0][i][c];
      p[1] = nx[1][k][c];
      p[2] = nx[2][j][c];
      if (min({p[0], p[1], p[2]}) == -1) continue;
      s += f[p[0] + 1][p[1] + 1][p[2] + 1];
    }
    f[i][k][j] = s;
  }
  print(f[0][0][0] - 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"