#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/exp/minimum_enclosing_circle.hpp"
#include "YRS/debug.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  Z [C, i, k, j] = minimum_enclosing_circle(p);
  static constexpr RE eps = 1e-9L;
  string ans(N, '0');
  FOR(i, N) {
    if (C.edge(p[i], eps)) ++ans[i];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"