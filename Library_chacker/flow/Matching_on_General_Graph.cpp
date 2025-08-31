#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/flower.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  flower FL(n);
  while (m--) {
    INT(x, y);
    FL.add(x, y);
  }
  int ans = FL.solve();
  vector<int> matching = FL.match;
  UL(ans);
  FOR(i, n) {
    if (matching[i] < i) {
      UL(matching[i], i);
    }
  }
}
#include "YRS/Z_H/main.hpp"