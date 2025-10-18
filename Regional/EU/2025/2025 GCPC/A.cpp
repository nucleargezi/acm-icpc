#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(l, r);
  ll ans;
  if (l == r) ans = l * 3;
  else if (l < r) ans = (l + r) * 2;
  else {
    if (l == r + 1) ans = l + r;
    else if (l == r + 2) ans = l * 3 - 3;
    else ans = (l + r) * 2;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"