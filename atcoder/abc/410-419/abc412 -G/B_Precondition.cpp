#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s, t);
  char pr = s[0];
  s.erase(s.begin());
  set<char> se {t.begin(), t.end()};
  for (char c : s){
    if (c >= 'A' and c <= 'Z' and not se.contains(pr)) iroha No();
    pr = c;
  }
  Yes();
}
#include "MeIoN_Lib/Z_H/main.hpp"