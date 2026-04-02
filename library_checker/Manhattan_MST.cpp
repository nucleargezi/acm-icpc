#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/exp/mst.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(point<ll>, p, N);
  meion e = manhattan_mst(p);
  dsu g(N);
  ll ans = 0;
  vector<PII> es;
  for (meion [c, i, k] : e) {
    if (g.merge(i, k)) ans += c, es.emplace_back(i, k);
  }
  UL(ans);
  for (meion x : es) UL(x);
}
#include "YRS/Z_H/main.hpp"