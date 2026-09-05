#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_conv.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, g, N - 1);
  semi_online_conv<mint> cv(move(g));
  fps f(N);
  f[0] = 1;
  FOR(i, 1, N) f[i] = cv(f[i - 1]);
  print(f);
}

int main() { Yorisou(); }