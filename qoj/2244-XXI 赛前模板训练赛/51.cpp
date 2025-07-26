#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/off_line/K_cdq.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<array<int, 4>> a(n);
  IN(a);
  K_cdq<int, 4> seg(a);
  print("{}", SUM(seg.keis()));
}
#include "MeIoN_Lib/Z_H/main.hpp"