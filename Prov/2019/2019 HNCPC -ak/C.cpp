#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/string/zfunction.hpp"

// #define tests
using mint = M17;
int N, M;
void yorisou() {
  VEC(int, s, N);
  FOR(i, N) s[i] -= 1;
  reverse(s);
  Z z = z_function(s);
  z.ep(0);

  int ans = 0;
  vector<int> max(M);
  FOR(i, N) chmax(max[s[i]], z[i + 1] + 1);
  FOR(i, M) ans ^= (mint(3).pow(i + 1) * (N + 1 - max[i])).val;
  print(ans);
}
void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"