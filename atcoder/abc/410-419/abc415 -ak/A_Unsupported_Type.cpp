#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n);
  set<int> se;
  FOR(i, n) {
    INT(x);
    se.emplace(x);
  }
  INT(x);
  Yes(se.contains(x));
}
#include "MeIoN_Lib/Z_H/main.hpp"