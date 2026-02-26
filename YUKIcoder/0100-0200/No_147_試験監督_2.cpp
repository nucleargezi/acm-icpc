#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/line/mat.hpp"

using mint = M17;
using M = mat<mint>;
void Yorisou() {
  INT(N);
  mint s = 1;
  FOR(N) {
    mint_t<mint::get_mod() - 1> b;
    LL(a);
    STR(sb);
    for (int x : sb) b = b * 10 + x - '0';
    int pw = b.val();
    if (pw == 0) pw += mint::get_mod() - 1;
    M g(2);
    g[0][0] = 1, g[0][1] = 1;
    g[1][0] = 1;
    g = g.pow(a - 1);
    cerr << g.a << '\n';
    s *= (g[0][0] + g[0][1] + g[1][0] + g[1][1]).pow(pw);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"