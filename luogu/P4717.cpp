#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/sps/bit.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  N = 1 << N;
  VEC(mint, f, N);
  VEC(mint, g, N);
  print(or_conv(f, g));
  print(and_conv(f, g));
  print(xor_conv(f, g));
}

int main() {
  Yorisou();
  return 0;
}