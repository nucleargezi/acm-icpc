#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/kmp.hpp"

// #define tests
void Yorisou() {
  S(s);
  meion ans = get_next(s).first;
  ans.erase(ans.begin());
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"