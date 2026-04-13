#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/inc_mst.hpp"

void Yorisou() {
  INT(N, M);
  inc_mst<int> g(N);
  FOR(i, M) {
    INT(x, y, w);
    print(g.add(x, y, w, i));
  }
}

int main() {
  Yorisou();
  return 0;
}