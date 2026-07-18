#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/sps/bit.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, 1 << N);
  VEC(mint, g, 1 << N);
  print(xor_conv(f, g));
}

int main() {
  Yorisou();
  return 0;
}