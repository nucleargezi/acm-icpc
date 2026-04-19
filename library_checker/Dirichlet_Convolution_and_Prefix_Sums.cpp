#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/diri.hpp"

using mint = M99;
void Yorisou() {
  LL(N);
  diri X(N);
  int n = X.n;
  vc<mint> f(n), g(n);
  FOR(i, 1, n) IN(f[i]);
  FOR(i, 1, n) IN(g[i]);
  f = X.conv(f, g);
  f.erase(bg(f));
  print(f);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}