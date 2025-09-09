#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  hash_map<int> mp;
  int ans = 0;
  FOR(i, n) {
    int x = std::min(i, n - i - 1);
    ll c = a[i] - x;
    if (c > 0) {
      chmax(ans, ++mp[c]);
    }
  }
  UL(n - ans);
}
#include "YRS/Z_H/main.hpp"