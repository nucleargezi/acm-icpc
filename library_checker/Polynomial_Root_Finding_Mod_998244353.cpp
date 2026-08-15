#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/find_root.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N + 1);
  f = find_root(f);
  print(si(f));
  print(f);
}

int main() {
  Yorisou();
  return 0;
}