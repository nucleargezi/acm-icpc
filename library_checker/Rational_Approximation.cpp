#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/rational_bina.hpp"

void Yorisou() {
  LL(N, x, y);
  Z [a, b, c, d] = rational_bina([&](ll a, ll b) -> bool {
    return a * y <= b * x;
  }, N);
  if (a * y == b * x) print(a, b, a, b);
  else print(a, b, c, d);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}