#include "YRS/all.hpp"
#include "YRS/pr/min_25.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
constexpr mint in = mint(6).inv();
void Yorisou() {
  LL(N);
  psum<mint> a(N), b(N);
  a.sum();
  b.ke([&](ll x) { return mint(x) * (x + 1) * (x << 1 | 1) * in; });
  Z fnp = [&](ll x) { return b[x] - a[x]; };
  Z fnpk = [&](ll x) { return mint(x) * (x - 1); };
  print(min_25<mint>(N, fnpk, fnp));
}

int main() { Yorisou(); }