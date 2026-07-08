#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/find_minsz_ok_cyc.hpp"

void Yorisou() {
  INT(N, M);
  retsu<int> g(N, N, inf<int>);
  FOR(M) {
    INT(a, b, c, d);
    --a, --b;
    g[a][b] = -c;
    g[b][a] = -d;
  }
  print(find_minsz_ok_cyc(std::move(g)));
}

int main() {
  Yorisou();
  return 0;
}