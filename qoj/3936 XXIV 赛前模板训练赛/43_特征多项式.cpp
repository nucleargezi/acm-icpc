#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/char_poly.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  vc<vc<mint>> a(N, vc<mint>(N));
  IN(a);
  print(char_poly(a));
}

int main() {
  Yorisou();
  return 0;
}