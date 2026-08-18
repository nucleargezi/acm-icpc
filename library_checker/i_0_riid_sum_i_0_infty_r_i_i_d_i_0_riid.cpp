#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/sum_of_geom_poly.hpp"
#include "YRS/mod/powtable.hpp"

using mint = M99;
void Yorisou() {
  LL(r, d);
  fps f = pow_table_2<mint>(d, d);
  print(sum_of_geom_poly<mint>(f, r));
}

int main() { Yorisou(); }