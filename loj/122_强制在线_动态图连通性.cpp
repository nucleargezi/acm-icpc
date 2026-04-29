#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/dynamic_connect.hpp"

void Yorisou() {
  INT(N, Q);
  dynamic_connect<dc_mono> g(N);
  int ls = 0;
  FOR(Q) {
    INT(op, x, y);
    x ^= ls, y ^= ls;
    --x, --y;
    if (op == 0) g.link(x, y);
    if (op == 1) g.cut(x, y);
    if (op == 2) {
      bool f = g.ck(x, y);
      ls = (f ? x : y) + 1;
      print("NY"[f]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}