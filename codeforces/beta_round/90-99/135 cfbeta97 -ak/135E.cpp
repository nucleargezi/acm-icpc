#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
binom<mint> X;
mint f(int x, int k) {
  mint rs = k > 1 ? (mint(k).pow(x + 1) - 1) / (k - 1) : x;
  --x;
  FOR(i, x + 2, x + k + 1) {
    mint g = X.fac(k) * X.ifac(k - i + x).pow(2);
    if (i - x >= x + 1) {
      rs += g * X.fac(k - i + x + x);
    } else {
      rs += g * X.fac(k) * mint(k).pow(x + x - i);
    }
  }
  return rs;
}

void Yorisou() {
  INT(K, W);
  print(f(W + 1, K) - f(W, K));
}

int main() {
  Yorisou();
  return 0;
}