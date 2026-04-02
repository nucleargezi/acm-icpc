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
  ll ans = inf<ll>;
  FOR(N) {
    STR(s);
    int mx = 1;
    for (char c : s) chmax(mx, isdigit(c) ? c - '0' : c - 'A' + 10);
    chmin(ans, stoll(s, 0, mx + 1));
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"