#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/exp/euclidean_mst.hpp"

using re = ld;
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  re s = 0;
  for (var [i, k] : euclidean_mst(a)) {
    s += (a[i] - a[k]).length();
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}