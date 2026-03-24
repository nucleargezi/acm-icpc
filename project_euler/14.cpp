#include "YRS/all.hpp"

int f(ll x) {
  int s{};
  while (x != 1) {
    if (x & 1) x = 3 * x + 1;
    else x >>= 1;
    ++s;
  }
  return s;
}
void Yorisou() {
  int mx = -1, s = -1;
  FOR(i, 1, 1'000'001) if (chmax(mx, f(i))) s = i;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"