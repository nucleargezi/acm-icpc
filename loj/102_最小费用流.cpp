#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/mcf.hpp"

void Yorisou() {
  INT(N, M);
  mcf<ll, ll> g(N);
  FOR(M) {
    INT(x, y, f, c);
    --x, --y;
    g.add(x, y, f, c);
  }
  print(g.flow(0, N - 1));
}

int main() {
  Yorisou();
  return 0;
}