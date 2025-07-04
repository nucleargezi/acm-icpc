#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector<int> a, b;
  FOR(i, 1, n + 1, 2) a += i;
  FOR(i, 2, n + 1, 2) b += i;
  reverse(b);
  UL(a + b);
}
#include "MeIoN_Lib/Z_H/main.hpp"