#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/dmint_t.hpp"
#include "YRS/fps/find_root.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, P);
  mint::set_mod(P);
  VEC(mint, f, N + 1);
  Z s = find_root(f);
  print(si(s));
  sort(s);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}