#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(Q);
  VEC(int, n, Q);
  int N = QMAX(n);
  vc<mint> e(N + 1);
  FOR(i, 1, N + 1) e[i] = ifac(i);
  Z g = ofps<mint>(
    [&](Z f, Z h) { return 1 + val<mint>(e) * f; },
    [](Z f, Z h) { return f * f - f; }
  );
  for (int x : n) print(g.get<1>()[x] / g.get<0>()[x]);
}

int main() { Yorisou(); }