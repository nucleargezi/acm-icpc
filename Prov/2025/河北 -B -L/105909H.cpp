#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s);
  if (s.substr(len(s) - 12) == "isallyouneed") {
    Yes();
    FOR(12) s.pop_back();
    UL(s);
  } else {
    No();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"