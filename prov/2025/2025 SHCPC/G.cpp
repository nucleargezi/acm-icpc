#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/primtable.hpp"

// #define tests
void Yorisou() {
  INT(N);
  vector p = primtable(N + 40 * N);
  int x = p[upper_bound(p, N)];
  vector a(N, vector<int>(N));
  FOR(i, N) FOR(k, N) a[i][k] = i * x + k + 1;
  FOR(i, N) print(a[i]);
}
#include "YRS/Z_H/main.hpp"