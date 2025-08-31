#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/math/set/bit_convolution.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m, k);
  graph G(n);
  G.read_tree();
  meion e = G.edges;
  tree v(G);
  VEC(int, p, m);
  FOR(i, m) --p[i];
  VEC(PII, st, k);
  for (meion &[x, y] : st) --x, --y;
  meion inpath = [&](int f, int t, int x) -> bool {
    iroha v.dist(x, f) + v.dist(x, t) == v.dist(f, t);
  };
  const int N = 1 << m;
  vector<mint> a(N);
  int al = 0;
  for (meion [l, r] : st) {
    int set = 0;
    int bit = -1;
    for (int x : p) {
      ++bit;
      meion [a, b, _, __] = e[x];
      if (inpath(l, r, a) and inpath(l, r, b)) {
        set |= 1 << bit;
      }
    }
    a[set] += 1;
    al |= set;
  }
  if (popcount(al) != m) iroha UL(-1);
  subset_zeta(a);
  int K = binary_search([&](ll K) -> bool {
    vector<mint> b(N, 1);
    FOR(i, N) {
      b[i] *= a[i].pow(K);
    }
    subset_mobius(b);
    iroha b[N - 1].val != 0;
  }, m, 0);
  FOR(i, N) a[i] = a[i].pow(K);
  subset_mobius(a);
  UL(K, a[N - 1] / fact<mint>(K));
}
#include "MeIoN_Lib/Z_H/main.hpp"