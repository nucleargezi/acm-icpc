#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/mst_kru.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T3<int>, es, M);
  for (Z &[a, b, c] : es) --a, --b;
  print(mst_kru<ll>(N, es).fi);
}

int main() {
  Yorisou();
  return 0;
}