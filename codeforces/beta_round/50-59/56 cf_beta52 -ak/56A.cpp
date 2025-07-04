#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  int ans = 0;
  set<string> se {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM",
      "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
  FOR(n) {
    S(s);
    if (std::isdigit(s[0])) {
      ll x = std::stoll(s);
      ans += x < 18;
    } else {
      ans += se.contains(s);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"