#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/exp/euclidean_mst.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  for (var [a, b] : euclidean_mst(a)) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}