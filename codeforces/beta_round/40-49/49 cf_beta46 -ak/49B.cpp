#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  SV(a, '0');
  SV(b, '0');
  reverse(a);
  reverse(b);
  while (len(a) != len(b)) (len(a) < len(b) ? a : b) += 0;
  ll mx = MAX(QMAX(a), QMAX(b)) + 1;
  a += 0;
  b += 0;
  int r = 0;
  FOR(i, len(a)) {
    a[i] += b[i] + r;
    r = a[i] / mx;
    a[i] %= mx;
  }
  while (a.back() == 0) a.pop_back();
  UL(len(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"