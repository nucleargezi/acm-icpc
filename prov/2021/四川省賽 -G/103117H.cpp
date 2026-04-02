#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  S(s);
  const int n = len(s);
  if (s == "ikimasu") iroha UL("itte");
  meion del = [&](int n) -> void { FOR(i, n) pop(s); };
  vector<pair<string, string>> ops {{"rimasu", "tte"}, {"mimasu", "nde"},
      {"bimasu", "nde"}, {"nimasu", "nde"}, {"kimasu", "ite"},
      {"gimasu", "ide"}, {"shimasu", "shite"}, {"chimasu", "tte"},
      {"imasu", "tte"}};
  for (meion [suf, cat] : ops) {
    if (s.substr(n - len(suf)) == suf) {
      del(len(suf));
      iroha UL(s + cat);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"