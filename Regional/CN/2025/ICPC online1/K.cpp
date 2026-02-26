#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/taylor.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, Q);
  mint in = mint(N).inv();
  vc<vc<mint>> ans;
  FOR(K, N + 1) {
    fps f;
    FOR(i, N + 1) {
      if (2 * N - K * i - i - 2 < 0) break;
      f.ep(CC(N, i) * CC(2 * N - K * i - i - 2, N - i - 1) * in);
      if (i == N) f.back() = i * K == N - 1;
    }
    if (not K) f.resize(N + 1, 0), f.back() = N - 1 == 0;
    f = taylor<mint>(f, -1);
    ans.ep(f);
  }
  FOR(Q) {
    INT(M, K);
    print( M < len(ans[K]) ? ans[K][M] : 0);
  }
}
#include "YRS/aa/main.hpp"