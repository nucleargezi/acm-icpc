#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(N);
  STR(s);
  fps a(N);
  FOR(i, N) if (s[i] == '1') a[i] = ifac(i);
  if (s[0] == '1') a[0] = 1;
  Z f = ofps<T>([&](Z b) { return integ(1 + val<mint>(a) * b * b * invs(2)); });
  FOR(i, 1, N + 1) print(f[i] * fac(i));
}

int main() { Yorisou(); }