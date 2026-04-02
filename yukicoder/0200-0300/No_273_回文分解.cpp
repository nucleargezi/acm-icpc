#include "YRS/all.hpp"
#include "YRS/string/manacher.hpp"

void Yorisou() {
  STR(s);
  int ans = 0;
  for (Z [l, r] : manacher(s.substr(0, si(s) - 1))) chmax(ans, r - l);
  for (Z [l, r] : manacher(s.substr(1))) chmax(ans, r - l);
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"