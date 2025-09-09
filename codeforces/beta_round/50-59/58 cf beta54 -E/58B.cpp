#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/PR/factors.hpp"
// #define tests
void Yorisou() {
  INT(n);
  meion fac = factor(n);
  vector<int> ans;
  while (n != 1) {
    ans.emplace_back(n);
    n /= fac.back().first;
    if (not --fac.back().second) pop(fac);
  }
  ans.emplace_back(1);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"