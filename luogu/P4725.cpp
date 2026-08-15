#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/log.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(log(f));
}

int main() {
  Yorisou();
  return 0;
}