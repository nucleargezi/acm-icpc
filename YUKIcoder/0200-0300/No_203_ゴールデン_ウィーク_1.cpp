#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/run_length.hpp"

void Yorisou() {
  STR(s, t);
  int ans = 0;
  for (Z [x, y] : run_length(s + t)) {
    if (x == 'o') chmax(ans, y);
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"