#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/floor_sum_line.hpp"

void Yorisou() {
  LL(N, p, a, b);
  print(floor_sum_line<ll, ll>(0, N, a, b, p));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}