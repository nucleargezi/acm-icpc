#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  set<string> se{"ABC", "ARC", "AGC", "AHC"};
  FOR(3) {
    S(s);
    se -= s;
  }
  UL(*se.begin());
}
#include "MeIoN_Lib/Z_H/main.hpp"