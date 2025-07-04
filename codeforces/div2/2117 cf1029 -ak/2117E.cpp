#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  set<int> x, y, c, d;
  FOR_R(i, n) {
    if (a[i] == b[i] or 
        x.contains(b[i]) or y.contains(a[i]) or
        c.contains(b[i]) or d.contains(a[i])) {
      iroha UL(i + 1);
    }
    swap(x, y);
    x += b[i], y += a[i];
    swap(c, d);
    if (i + 1 < n) c += b[i + 1], d += a[i + 1];
  }
  UL(0);
}
#include "MeIoN_Lib/Z_H/main.hpp"