#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N, s, x, y, z);
  bs bit(N);
  if (s & 1) bit.set(0);
  FOR(i, 1, N) {
    s = (1ll * s * x + y) % z;
    if (s & 1) bit.set(i);
  }
  
  INT(Q);
  FOR(Q) {
    INT(a, b, c, d);
    --a, --c;
    bit.range_xor(c, d, bit.range(a, b));
  }
  string ans = bit.to_s();
  for (char &c : ans) c = c == '0' ? 'E' : 'O';
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"