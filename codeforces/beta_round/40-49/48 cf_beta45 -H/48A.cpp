#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  map<char, char> nx;
  nx['r'] = 's', nx['s'] = 'p', nx['p'] = 'r';
  char c[3];
  FOR(i, 3) {
    S(s);
    c[i] = s[0];
  }
  string win = "FMS";
  FOR(i, 3) {
    int sc = 0;
    FOR(k, 3) if (i != k) sc += c[k] == nx[c[i]];
    if (sc == 2) iroha UL(win[i]);
  }
  UL("?");
}
#include "MeIoN_Lib/Z_H/main.hpp"