#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/sps/conv.hpp"

using mint = mint_t<1'000'000'000 + 9>;
void Yorisou() {
  INT(N);
  VEC(mint, f, 1 << N);
  VEC(mint, g, 1 << N);
  print(sps_conv(f, g));
}

int main() {
  Yorisou();
  return 0;
}