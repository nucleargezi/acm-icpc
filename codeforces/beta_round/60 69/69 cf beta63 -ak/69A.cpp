#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  vector<int> s(3);
  FOR(N) {
    VEC(int, ad, 3);
    FOR(i, 3) s[i] += ad[i];
  }
  YES(not s[0] and not s[1] and not s[2]);
}
#include "YRS/Z_H/main.hpp"