#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/two_sat.hpp"

void Yorisou() {
  INT(N, M);
  sat g(N);
  FOR(M) {
    INT(x, a, y, b);
    --x, --y;
    g.ban(x, y, not a, not b);
  }
  if (g.slv()) {
    Yes();
    Z r = g();
    print(vc<int>(all(r)));
  } else No();
}

int main() {
  Yorisou();
  return 0;
}