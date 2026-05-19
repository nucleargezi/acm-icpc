#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/line/mat_ar.hpp"

using mint = M99;
binom<mint> C;
void Yorisou() {
  LL(N, D);
  mint s;
  Z f = [&](ll x) -> mint {
    mat_ar<mint, 2> a;
    a[0][0] = C(D - 1, x);
    a[0][1] = a[1][0] = C(D - 1, x - 1);
    a[1][1] = C(D - 1, x - 2);
    a = a.pow(N);
    return a[0][0] + a[1][1];
  };
  FOR(i, D + 2) s += f(i);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}