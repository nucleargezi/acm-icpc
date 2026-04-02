#include "YRS/all.hpp"

void Yorisou() {
  STR(s);
  map<int, int> c;
  for (int x : s) ++c[x];
  print(min({c['t'], c['r'], c['e'] / 2}));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"