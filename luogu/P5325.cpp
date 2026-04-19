#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/psum.hpp"
#include "YRS/pr/min_25.hpp"

using mint = M11;
constexpr mint in = mint(6).inv();
void Yorisou() {
  LL(N);
  psum<mint> a(N), b(N);
  a.sum();
  b.ke([&](ll x) { return mint(x) * (x + 1) * (x << 1 | 1) * in; });
  Z pfn = [&](ll x) { return b[x] - a[x]; };
  Z fn = [&](ll x) { return mint(x) * (x - 1); };
  print(min_25_2<mint>(N, fn, pfn));
}

int main() {
  Yorisou();
  return 0;
}