#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/runs.hpp"

// #define tests
void Yorisou() {
  S(s);
  meion ans = runs<1>(s);
  print("{}", len(ans));
  for (meion [l, r, p] : ans) {
    print("{} {} {}", l + 1, r, p);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"