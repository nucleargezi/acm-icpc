#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  hash_map<int> mp;
  FOR(3 * N) {
    INT(x);
    ++mp[x];
  }
  int ans = 0, rs = 0;
  for (Z [k, c] : mp.get_all()) {
    ans += c / 2;
    rs += c & 1;
  }
  print(ans + rs / 4);
}
#include "YRS/aa/main.hpp"