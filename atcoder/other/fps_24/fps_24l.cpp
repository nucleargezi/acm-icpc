#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(N);
  vc<mint> g(N + 1);
  FOR(i, 2, N + 1) g[i] = 1;
  Z f = ofps<mint>([&](Z a) { return 1 + integ(a * val<mint>(g)); });
  print(f[N] * fac(N));
}

int main() { Yorisou(); }