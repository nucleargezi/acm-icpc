#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  VEC(int, b, n);
  vector<int> a = b;
  VEC(T3<int>, op, q);
  for (meion &[x, y, z] : op) --x, --y, --z;
  for (meion [x, y, z] : std::views::reverse(op)) {
    if (z == x) {
      chmax(a[y], a[z]);
    } else if (z == y) {
      chmax(a[x], a[z]);
    } else {
      chmax(a[x], a[z]);
      chmax(a[y], a[z]);
      a[z] = 0;
    }
  }
  vector ans = a;
  for (meion [x, y, z] : op) {
    a[z] = MIN(a[x], a[y]);
  }
  if (a == b) print("{}", ans);
  else print("{}", -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"