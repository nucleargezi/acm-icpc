#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

bool ck(int x) {
  if (x % 3 == 0) return 1;
  for (char c : to_string(x)) if (c == '3') return 1;
  return 0;
};
void Yorisou() {
  INT(l, r);
  ++r;
  FOR(i, l, r) if (ck(i)) print(i);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"