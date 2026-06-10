#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/hs.hpp"
#include "YRS/poly/fps.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, K);
  STR(s);
  Z gen = [&]() {
    hash_t hs(s);
    fps f(N + 1);
    FOR(d, 1, N + 1) {
      f[d] += 1;
      FOR(i, 2, N + 1) {
        if (i * d > N or hs(0, d) != hs(i * d - d, i * d)) break;
        f[i * d] += 1;
      }
    }
    reverse(s);
    return f;
  };
  fps f = X.conv(gen(), gen());
  if (K == 0) return print(f[N]);
  mint rs;
  FOR(i, K, N + 1) rs += X.C(i - 1, K - 1) * f[N - i];
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}