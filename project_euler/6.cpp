#include "YRS/all.hpp"

void Yorisou() {
  ll s{}, ss{};
  FOR(i, 1, 101) s += i, ss += i * i;
  print(s * s - ss);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"