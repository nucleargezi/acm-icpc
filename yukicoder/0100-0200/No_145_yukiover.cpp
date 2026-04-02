#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  map<char, int> cnt;
  for (char c : s) ++cnt[c];
  print(bina([&](int x) -> bool {
    Z mp = cnt;
    for (char c : "yuki") {
      FOR(i, c + 1, 'z' + 1) x -= mp[i], mp[i] = 0;
      if (x <= 0) return 1;
      if ((mp[c] -= x) < 0) return 0;
    }
    for (Z [a, b] : mp) x -= b;
    return x <= 0;
  }, 0, N + 1));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"