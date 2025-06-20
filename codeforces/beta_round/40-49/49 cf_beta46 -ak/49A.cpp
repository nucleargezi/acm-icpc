#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  string s, e;
  while (std::cin >> e) s += e;
  while (len(s) and not std::isalpha(s.back())) s.pop_back();
  for (char &c : s) if (c >= 'A' and c <= 'Z') c -= 'A' - 'a';
  YES(set<char>{'a', 'e', 'i', 'o', 'u', 'y'}.contains(s.back()));
}
#include "MeIoN_Lib/Z_H/main.hpp"