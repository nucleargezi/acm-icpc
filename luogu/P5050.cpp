#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/multi.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(mint, f, N + 1);
  VEC(mint, q, Q);
  for (mint x : eval(f, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}