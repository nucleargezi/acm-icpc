#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_conv.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  fps f(N + 1), d(N + 1);
  f[1] = 1;
  FOR(i, 1, N + 1) d[i] = 1;
  online_conv<mint> cv;
  FOR(i, 2, N + 1) {
    f[i] = cv(f[i - 1], d[i - 1]) * invs(i - 1);
    FOR(k, i, N + 1, i) d[k] += f[i] * i;
  }
  mint s;
  FOR(i, 1, N) s += f[i] * f[N - i];
  if (~N & 1) s -= f[N >> 1];
  print(f[N] - s * invs(2));
}

int main() { Yorisou(); }