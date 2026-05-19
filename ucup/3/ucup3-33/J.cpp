#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/min_line.hpp"

void yorisou() {
  INT(N, P, Q);
  ll a = 0, b = 0;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      a = (a + P - y) % P;
      b = (b + P - x) % P;
    } else {
      INT(l, r);
      --l;
      print(max_line(l, r, a, b, P).se);
    }
  }
}

int main() {
  yorisou();
  return 0;
}