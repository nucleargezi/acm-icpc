#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/stirling_1.hpp"

using mint = mint_t<167772161>;
void Yorisou() {
  INT(N, K);
  print(stirling_1_k<mint>(N, K));
}

int main() { Yorisou(); }