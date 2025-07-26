#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/flow/BM.hpp"

// #define tests
void Yorisou() {
  INT(L, R, m);
  graph<int> v(L + R);
  FOR(m) {
    INT(x, y);
    v.add(x, y + L);
  }
  v.build();

  B_matching BM(v);
  meion match = BM.matching();
  UL(len(match));
  for (meion [x, y] : match) {
    print("{} {}", x, y - L);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"