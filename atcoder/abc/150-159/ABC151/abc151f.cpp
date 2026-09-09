#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/exp/minimum_enclosing_circle.hpp"

using re = ld;
using P = point<re>;

void Yorisou() {
  INT(N);
  VEC(P, a, N);
  Z [C, i, k, j] = minimum_enclosing_circle<re, 1e-12l>(a);
  print(C.R);
}

int main() { Yorisou(); }