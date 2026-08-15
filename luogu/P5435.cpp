#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/gcd_fast.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  vc<mint> s(N);
  gcd_fast g(max(QMAX(a), QMAX(b)));
  FOR(i, N) {
    mint d = i + 1;
    FOR(k, N) { 
      s[i] += d * g(a[i], b[k]); 
      d *= i + 1;
    }
  }
  for (Z x : s) print(x);
}

int main() {
  Yorisou();
  return 0;
}