#include "YRS/all.hpp"
#include "YRS/flow/BM.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  graph g(N << 1);
  FOR(i, N) FOR(k, N) if (a[i] != k) g.add(i, k + N);
  g.build();
  vc<PII> mat = B_matching(g).matching();
  if (len(mat) != N) return print(-1);
  FOR(i, N) print(mat[i].se - N);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"