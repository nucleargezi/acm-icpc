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
  LL(n, k);
  FOR(n) {
    LL(n, m);
    if (n > m) std::swap(n, m);
    if (k == 1) {
      UL(n % 2 & m % 2 ? '-' : '+');
    } else {
      if (n % (k + 1) == 0) {
        UL("+");
      } else {
        UL(m - n + 1 & 1 ^ (n % (k + 1 << 1) > k) ? '-' : '+');
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"