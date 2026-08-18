#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/stirling_1.hpp"

using mint = mint_t<167772161>;
void Yorisou() {
  INT(N);
  print(stirling_1_n<mint>(N));
}

int main() { Yorisou(); }