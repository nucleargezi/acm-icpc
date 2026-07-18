#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/min_25.hpp"

using mint = M11;
void Yorisou() {
  LL(N);
  if (N == 1) return print(1);
  psum<mint> f(N), g(N);
  f.sum();
  g.count();
  Z fpk = [&](ll p, ll k) -> mint { return p ^ k; };
  Z pfp = [&](ll x) -> mint { return f[x] - g[x]; };
  print(min_25<mint>(N, fpk, pfp) + 2);
}

int main() {
  Yorisou();
  return 0;
}