#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/SA.hpp"

// #define tests
void Yorisou() {
  S(s);
  SA<1> sa(s);
  meion &ans = sa.sa;
  for (int &x : ans) ++x;
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"