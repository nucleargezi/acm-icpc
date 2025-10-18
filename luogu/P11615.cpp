#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
void Yorisou() {
  INT(N);
  hash_map<ull> H(N);
  ull ans = 0;
  FOR(i, N) {
    ull x, y;
    IN(x, y);
    ans += H[x] * (i + 1);
    H[x] = y;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"