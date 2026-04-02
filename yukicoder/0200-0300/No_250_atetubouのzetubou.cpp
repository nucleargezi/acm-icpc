#include "YRS/all.hpp"
#include "YRS/nt/bigint/big.hpp"

using G = bigint;
const G L = G(1'000'000'000'000'000'000ull).pow(4);
G C(int N, int K) {
  chmin(K, N - K);
  if (K > 200) return L;
  G x = 1;
  FOR(i, K) {
    x *= N - i;
    if (x >= L) return L;
  }
  FOR(i, 1, K + 1) x /= i;
  return x;
}
void Yorisou() {
  INT(d, x);
  ULL(t);
  print(C(d + x - 1, d - 1) <= t ? "AC" : "ZETUBOU");
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"