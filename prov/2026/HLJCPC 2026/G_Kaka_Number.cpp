#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M99;
void Yorisou() {
  INT(x);
  if (x == 0) print(0);
  else print(mint(x) * mint(10).pow(x - 1));
}

int main() {
  Yorisou();
  return 0;
}