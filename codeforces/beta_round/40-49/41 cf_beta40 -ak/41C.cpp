#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s);
  bool upd = 1;
  while (upd) {
    upd = 0;
    FOR(i, 1, len(s) - 3) {
      if (s.substr(i, 3) == "dot") {
        s.replace(i, 3, ".");
        upd = 1;
        break;
      }
    }
  }
  FOR(i, 1, len(s) - 2) {
    if (s.substr(i, 2) == "at") {
      s.replace(i, 2, "@");
      iroha UL(s);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"