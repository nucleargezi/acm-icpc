#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  INT(N);
  vc<u8> f(N + 1);
  FOR(i, 2, N + 1) {
    set<int> s;
    s.eb(f[i / 2] ^ f[i - i / 2]);
    if (i > 2) s.eb(f[i / 3] ^ f[i / 3 + (i % 3 > 1)] ^ f[i / 3 + (i % 3 > 0)]);
    FOR_R(k, 3) if (not s.contains(k)) f[i] = k;
  }
  print("AB"[f[N] == 0]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"