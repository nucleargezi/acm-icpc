#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  ll a[3]{};
  LL(x);
  a[--x] = 1;
  FOR(i, 3) {
    LL(l, r);
    std::swap(a[--l], a[--r]);
  }
  FOR(i, 3) if (a[i]) UL(i + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"