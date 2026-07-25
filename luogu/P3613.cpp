#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> a(N);
  FOR(Q) {
    INT(op, x, y);
    --x, --y;
    if (y >= si(a[x])) a[x].resize(y + 1);
    if (op == 1) {
      INT(w);
      a[x][y] = w;
    } else {
      print(a[x][y]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}