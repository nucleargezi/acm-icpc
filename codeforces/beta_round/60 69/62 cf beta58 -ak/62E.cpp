#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/rect_dense.hpp"

// #define tests
using T = array<int, 5>;
void Yorisou() {
  INT(N, M);
  vector<T> a(M - 1), b(M);
  FOR(i, M - 1) FOR(k, N) IN(a[i][k]);
  FOR(i, M) FOR(k, N) IN(b[i][k]);
  UL(rect_dense_flow(a, b, M, N));
}
#include "YRS/Z_H/main.hpp"