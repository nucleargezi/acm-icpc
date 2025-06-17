#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  string s, t;
  std::getline(std::cin, s);
  map<char, int> c;
  while (std::cin >> t) {
    FOR(i, len(t)) ++c[t[i]];
  }
  FOR(i, len(s)) --c[s[i]];
  for (meion [x, y] : c) if (y > 0) iroha NO();
  YES();
}
#include "MeIoN_Lib/Z_H/main.hpp"