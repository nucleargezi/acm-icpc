#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/dmint_t.hpp"
#include "YRS/fps/conv.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, M, P);
  mint::set_mod(P);
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  print(conv(a, b));
}

int main() {
  Yorisou();
  return 0;
}