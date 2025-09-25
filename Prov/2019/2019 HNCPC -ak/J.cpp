#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
int N, M, K;
mint A[30], B[30];
void yorisou() {
  const mint iv = (mint(2).inv()).pow(M);
  mint ans;
  const int sz = 1 << M;
  vector<int> xs(sz);
  FOR(i, N) {
    VEC(int, a, M);
    std::fill(all(xs), 0);
    FOR(s, 1, sz) {
      int x = lowbit(s);
      xs[s] = xs[s ^ (1 << x)] ^ a[x];
    }
    mint sm;
    FOR(s, sz) {
      int x = xs[s];
      mint g = 1;
      FOR(i, K) g *= (x >> i & 1) ? B[i] : A[i];
      if (popcount(s) & 1) sm -= g;
      else sm += g;
    }
    ans += sm * iv;
  }
  print(ans);
}
void Yorisou() {
  mint t = 3;
  FOR(i, 30) {
    A[i] = mint(1) + t;
    B[i] = mint(1) - t;
    t *= t;
  }
  while (IN(N, M, K)) yorisou();
}
#include "YRS/Z_H/main.hpp"