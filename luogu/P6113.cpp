#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/flower.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  flower FL(n);
  while (m--) {
    INT(x, y);
    --x, --y;
    FL.add(x, y);
  }
  int ans = FL.solve();
  vector<int> matching = FL.match;
  pop(matching);
  for (int &x : matching) if (x == n) x = 0; else ++x;
  UL(ans);
  UL(matching);
}
#include "YRS/Z_H/main.hpp"