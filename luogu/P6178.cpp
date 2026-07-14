#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/matrix_tree.hpp"

void Yorisou() {
  INT(N, M, op);
  VEC(T3<int>, es, M);
  for (Z &[a, b, c] : es) --a, --b;
  print(matrix_tree(N, 0, es, op, 1'000'000'007));
}

int main() {
  Yorisou();
  return 0;
}