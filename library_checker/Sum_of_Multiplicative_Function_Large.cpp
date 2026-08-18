#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/min_25_large.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = mint_t<469762049>;
void Yorisou() {
  LL(N);
  mint a, b;
  IN(a, b);
  Z pre = [](ll x) {
    ll a = x, b = x + 1;
    (a & 1 ? b : a) >>= 1;
    return array<mint, 2>{x, mint(a) * b};
  };
  Z fpk = [&](ll p, int e) { return mint(a) * e + mint(b) * p; };
  print(min_25_large<mint>(N, array<mint, 2>{a, b}, fpk, pre));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}