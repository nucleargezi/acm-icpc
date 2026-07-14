#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/matrix_tree.hpp"

void Yorisou() {
  INT(N, M);
  vc<T3<int>> es(M);
  for (Z &[a, b, c] : es) {
    IN(a, b);
    c = 1;
    --a, --b;
    swap(a, b);
  }
  print(matrix_tree(N, 0, es, 1, 1'000'7));
}

int main() {
  Yorisou();
  return 0;
}