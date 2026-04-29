#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/mcf_ring.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  using E = tuple<int, int, ll, ll>;
  VEC(E, es, M);
  for (Z &[f, t, a, b] : es) --f, --t;
  print(mcf_ring(N, s, t, es));
}

int main() {
  Yorisou();
  return 0;
}