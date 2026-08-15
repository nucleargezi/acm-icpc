#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/matrix_tree.hpp"

void Yorisou() {
  INT(N, M, s);
  vc<T3<int>> es(M);
  for (Z &[a, b, c] : es) IN(a, b), c = 1;
  print(matrix_tree(N, s, es, 1, 998244353));
}

int main() {
  Yorisou();
  return 0;
}