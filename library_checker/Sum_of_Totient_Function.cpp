#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/du.hpp"

using mint = M99;
void Yorisou() {
  LL(x);
  print(phi_sum<mint>{}[x]);
}

int main() {
  Yorisou();
  return 0;
}