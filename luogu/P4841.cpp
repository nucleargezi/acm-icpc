#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_conv.hpp"

using mint = mint_t<1004535809>;
void Yorisou() {
  INT(N);
  fps a(N + 1);
  a[0] = 1;
  mint p = 1;
  FOR(i, 1, N + 1) a[i] = a[i - 1] * p, p *= 2;
  fps b(N - 1);
  FOR(i, N - 1) b[i] = a[i + 1] * ifac(i + 1);
  semi_online_conv<mint> cv(move(b));
  fps f(N + 1);
  f[1] = 1;
  FOR(i, 2, N + 1) f[i] = a[i] * ifac(i - 1) - cv(f[i - 1]);
  print(f[N] * fac(N - 1));
}

int main() { Yorisou(); }