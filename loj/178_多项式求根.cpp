#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/find_root.hpp"
#include "YRS/mod/dmint_t.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, p);
  mint::set_mod(p);
  VEC(mint, f, N + 1);
  fps_t<mint> X;
  f = X.find_root(f);
  print(si(f));
  sort(f, [&](var a, var b) -> bool { return a < b; });
  print(f);
}

int main() {
  Yorisou();
  return 0;
}