#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/line/01/sp.hpp"

using mint = M11;
using bs = sp<uint>;
void yorisou() {
  INT(N, K);
  VEC(uint, a, N);
  VEC(uint, b, K);
  for (uint x : b) if (x == 0) return print(0);
  bs sa;
  for (uint x : a) sa.add(x);
  mint s = mint(2).pow(N) - 1;
  FOR(m, 1 << K) {
    int msk = 0;
    FOR(i, K) if (m >> i & 1) msk |= b[i];
    bs sb;
    for (uint x : sa.a) sb.add(x & msk);
    if (not sb.contain(msk)) continue;
    mint t = mint(2).pow(N - si(sb));
    if (pc(m) & 1) s -= t;
    else s += t;
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}