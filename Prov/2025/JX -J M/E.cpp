#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/line/mat.hpp"

// #define tests
using mint = M99;
using MT = matrix<mint>;
void Yorisou() {
  INT(N, K);
  VEC(int, c, N);
  VEC(int, a, N);
  for (int &x : c) --x;
  vector<mint> s(K);
  MT cc(K), ccc(K);
  mint ans;
  FOR(i, N) {
    int f = c[i];
    FOR(k, K) {
      if (k == c[i]) continue;
      ans += ccc[f][k] * a[i];
      ccc[k][f] += cc[f][k] * a[i];
      cc[k][f] += s[k] * a[i];
    }
    s[f] += a[i];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"