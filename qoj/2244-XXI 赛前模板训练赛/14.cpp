#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

// #define tests
void Yorisou() {
  LL(n, m, s, t);
  --s, --t;
  max_flow FL(n, s, t);
  FOR(m) {
    LL(x, y, w);
    --x, --y;
    FL.add(x, y, w);
  }
  print("{}", FL.flow());
}
#include "MeIoN_Lib/Z_H/main.hpp"