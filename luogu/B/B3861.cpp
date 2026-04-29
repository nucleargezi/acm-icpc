#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"

void Yorisou() {
  INT(N);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g.add(f, i);
  }
  g.build();
  hld v(g);
  FOR(i, N) print(v.size(i));
}

int main() {
  Yorisou();
  return 0;
}