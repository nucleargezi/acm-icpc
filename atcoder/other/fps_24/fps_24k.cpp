#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(N);
  vc<mint> a(N + 1);
  a[1] = 1;
  FOR(i, 2, N + 1) a[i] = a[i - 1] * i;
  Z f = ofps<mint>([&](Z b) { return val<mint>(a) - b * val<mint>(a); });
  print(f[N]);
}

int main() { Yorisou(); }