#include "YRS/all.hpp"

void Yorisou() {
  STR(s);
  int ans = 0;
  for (char c : s) if (isdigit(c)) ans += c - '0';
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"