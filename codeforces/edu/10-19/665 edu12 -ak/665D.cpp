#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/lpf_table.hpp"
#include "MeIoN_Lib/graph/max_clique.hpp"

void before() {}

// #define tests
vector lpf = lpf_table(2'000'000);
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector v(n, vector<u8>(n));
  FOR(i, n) FOR(k, i) {
    if (lpf[a[i] + a[k]] == a[i] + a[k]) {
      v[i][k] = v[k][i] = 1;
    }
  }
  meion set = max_clique(v);
  UL(len(set));
  FOR(i, len(set)) set[i] = a[set[i]];
  UL(set);
}
#include "MeIoN_Lib/Z_H/main.hpp"