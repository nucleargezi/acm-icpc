#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mod_inv.hpp"

void Yorisou() {
  INT(N, p);
  FOR(i, 1, N + 1) print(mod_inv(i, p));
}

int main() {
  Yorisou();
  return 0;
}