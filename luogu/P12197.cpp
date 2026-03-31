#include "YRS/all.hpp"

void Yorisou() {
  int N = 1 << 11, l = 1 << 10;
  print(N, l);
  string s(N, 'a');
  FOR(i, N) s[i] += pc(i) & 1;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"