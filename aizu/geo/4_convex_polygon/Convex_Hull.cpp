#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  p = rearrange(p, hull<RE, 1>(p));
  N = len(p);
  pair<RE, RE> mx = inf<pair<RE, RE>>;
  int idx = 0;
  for (int i = 0; i < N; ++i)
    if (chmin(mx, pair{p[i].y, p[i].x})) idx = i;
  std::rotate(p.begin(), p.begin() + idx, p.end());
  UL(N);
  for (meion p : p) UL(p);
}
#include "YRS/Z_H/main.hpp"