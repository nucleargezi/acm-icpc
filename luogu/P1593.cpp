#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ke/geo_sum.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = mint_t<9901>;
void Yorisou() {
  INT(a, b);
  mint s = 1;
  for (var [p, e] : factor(a)) s *= geo_sum<mint>(p, e * b + 1);
  print(s);
}

int main() { Yorisou(); }