#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  std::cin.ignore();
  string s;
  vector<pair<string, string>> se;
  while (std::getline(std::cin, s)) {
    FOR(i, len(s)) {
      if (s[i] >= 'A' and s[i] <= 'Z') {
        se += pair{s.substr(i), s};
        break;
      }
    }
  }
  sort(se);
  FOR(i, n) {
    UL(se[i].second);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"