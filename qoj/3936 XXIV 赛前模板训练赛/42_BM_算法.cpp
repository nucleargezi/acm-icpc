#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/find_line.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  f = X.find_line(f);
  f.erase(bg(f));
  for (Z &x : f) x = -x;
  print(si(f));
  print(f);
}

int main() {
  Yorisou();
  return 0;
}