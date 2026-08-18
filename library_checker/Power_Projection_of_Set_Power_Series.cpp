#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/sps/pow_proj.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N, K);
  N = 1 << N;
  VEC(mint, f, N);
  VEC(mint, w, N);
  print(sps_pow_proj(f, w, K));
}

int main() {
  Yorisou();
  return 0;
}