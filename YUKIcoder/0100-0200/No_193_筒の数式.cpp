#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

int f(string &s) {
  s.insert(s.begin(), pop(s));
  if (not isdigit(s[0]) or not isdigit(s.back())) return -inf<int>;
  int r = 0, x = 0, op = '+';
  s += '+';
  for (char c : s) {
    if (not isdigit(c)) {
      if (op == '+') r += x;
      if (op == '-') r -= x;
      op = c;
      x = 0;
    } else {
      x = x * 10 + c - '0';
    }
  }
  pop(s);
  return r;
}
void Yorisou() {
  STR(s);
  int N = len(s), ans = -inf<int>;
  FOR(N) chmax(ans, f(s));
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"