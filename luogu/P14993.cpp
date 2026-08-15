#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/multi_geo.hpp"

using mint = M99;
void Yorisou() {
  INT(N, a, r);
  VEC(mint, f, N);
  print(inte_geo<mint>(f, a, r));
}

int main() {
  Yorisou();
  return 0;
}