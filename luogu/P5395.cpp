#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/stirling_2.hpp"

using mint = mint_t<167772161>;
void Yorisou() {
  INT(N);
  print(stirling_2_n<mint>(N, N));
}

int main() { Yorisou(); }