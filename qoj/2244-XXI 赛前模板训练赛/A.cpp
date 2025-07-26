#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/wildcard_match_fft.hpp"

// #define tests
using RE = double;
void Yorisou() {
  S(s, t);
  vector ans = wildcard_match_fft<RE>(s, t);
  for (int &x : ans) ++x;
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"