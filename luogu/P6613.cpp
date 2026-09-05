#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(N);
  ++N;
  VEC(mint, a, N);
  VEC(mint, b, N);
  Z s = ofps<mint>(
      [](Z g, Z h) {
        return 1 + integ(g * h);
      },
      [&](Z g, Z) {
        return val<mint>(a) * g + val<mint>(b);
      });
  Z &h = s.get<1>();
  fps f(N);
  f[0] = 1;
  FOR(i, 1, N) f[i] = h[i - 1] * invs(i);
  print(f);
}

int main() { Yorisou(); }