#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  S(s);
  int n = len(s);
  int x = 0;
  for (char c : s) x += not not std::islower(c);
  if (x * 2 >= n)
    std::ranges::transform(s, s.begin(), [](char c) { iroha std::tolower(c); });
  else
    std::ranges::transform(s, s.begin(), [](char c) { iroha std::toupper(c); });
  UL(s);
}
#include "YRS/Z_H/main.hpp"