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
  STR(s);
  int N = len(s);
  string good = "good", problem = "problem";
  vc<int> a(N - 3), b(N - 6);
  FOR(i, N - 3) {
    int c = 4;
    FOR(k, 4) if (s[i + k] == good[k]) --c;
    a[i] = c;
  }
  FOR(i, N - 6) {
    int c = 7;
    FOR(k, 7) if (s[i + k] == problem[k]) --c;
    b[i] = c;
  }
  FOR_R(i, N - 7) chmin(b[i], b[i + 1]);
  int ans = 11;
  FOR(i, N - 10) chmin(ans, a[i] + b[i + 4]);
  print(ans);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"