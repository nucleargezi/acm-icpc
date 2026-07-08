#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd_dual.hpp"
#include "YRS/al/m/mul.hpp"

using re = ld;
using DS = segd_dual<Mul<re>>;
using np = DS::np;
void Yorisou() {
  INT(N, M);
  constexpr int sz = 1'000'000'000;
  DS seg(-sz, sz);
  np t{};
  Z f = [&](int l, int r, re x) {
    chmax(l, -sz), chmin(r, sz);
    if (l < r) t = seg.apply(t, l, r, x);
  };
  FOR(N) {
    INT(x, h, l, r);
    f(x - h, x, re(100 - l) / 100);
    f(x + 1, x + h + 1, re(100 - r) / 100);
  }
  
  re s = 0;
  FOR(M) {
    INT(a, b);
    s += b * seg.get(t, a);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}