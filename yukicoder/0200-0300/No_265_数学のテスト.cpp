#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint_t.hpp"
// #include "YRS/mod/binom.hpp"

void Yorisou() {
  INT(N, d);
  STR(s);
  vc<ll> ans(++d);
  d = 0;
  for (int i = 0; i < N; ) {
    if (s[i] == 'd') {
      ++d, i += 2;
    } else if (s[i] == '}') {
      --d, ++i;
    } else if (s[i] == '+') {
      ++i;
    } else {
      int x = 1, c = 0;
      while (1) {
        if (s[i] == 'x') {
          ++c, ++i;
        } else if (isdigit(s[i])) {
          x *= s[i] - '0';
          ++i;
        } else if (s[i] == '*') {
          ++i;
        } else break;
      }
      FOR(d) x *= c, --c;
      if (c >= 0) ans[c] += x;
    }
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"