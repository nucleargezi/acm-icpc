#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/psum.hpp"
#include "YRS/pr/min_25.hpp"

using mint = mint_t<469762049>;
void Yorisou() {
  LL(N);
  mint a, b;
  IN(a, b);
  psum<mint> f(N), g(N);
  f.count();
  g.sum();
  Z fpk = [&](ll p, ll k) { return a * k + b * p; };
  Z pfp = [&](ll x) { return a * f[x] + b * g[x]; };
  print(min_25<mint>(N, fpk, pfp));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}