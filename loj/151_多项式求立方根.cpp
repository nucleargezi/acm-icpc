#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/kth_root.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N + 1);
  print(kth_root(f, 3));
}

int main() {
  Yorisou();
  return 0;
}