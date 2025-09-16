#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  ull x, y, r;
  IN(x, y);
  if (x == y) return print(-1);
  r = 1ull << std::max(topbit(x), topbit(y));
  print(r + r - std::max(x, y));
}
#include "YRS/Z_H/main.hpp"