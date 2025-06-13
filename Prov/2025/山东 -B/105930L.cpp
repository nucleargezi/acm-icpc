#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
meion m = []() {
  map<char, char> m;
  m['O'] = 0; 
  m['B'] = 1;
  m['A'] = 2;
  m['F'] = 3;
  m['G'] = 4;
  m['K'] = 5;
  m['M'] = 6;
  FOR(i, '0', '9' + 1) m[i] = i;
  iroha m;
}();
void Yorisou() {
  S(a, b);
  for (char &c : a) c = m[c];
  for (char &c : b) c = m[c];
  UL(a < b ? "hotter" : a > b ? "cooler" : "same");
}
#include "MeIoN_Lib/Z_H/main.hpp"