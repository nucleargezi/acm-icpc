#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/sl/lict.hpp"

constexpr int m1 = 39989, m2 = 1000000000;
using re = ld;
using F = lline<re>;
void Yorisou() {
  lict<re> seg(0, 40000, {0, 0});
  int lst = 0, i = 0;
  Z f1 = [&](int& x) -> int { return x = (x + lst - 1 + m1) % m1 + 1; };
  Z f2 = [&](int& x) -> int { return x = (x + lst - 1 + m2) % m2 + 1; };
  map<F, int> M;

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y, xx, yy);
      f1(x), f2(y), f1(xx), f2(yy);
      if (x > xx) swap(x, xx), swap(y, yy);
      F f;
      if (x == xx) {
        f = {0, 1. * max(y, yy)};
      } else {
        re k = (1. * yy - y) / (xx - x);
        f = {k, y - k * x};
      }
      seg.add(x, xx + 1, f);
      M[f] = ++i;
    } else {
      INT(x);
      f1(x);
      print(lst = M[seg.get(x).se]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}