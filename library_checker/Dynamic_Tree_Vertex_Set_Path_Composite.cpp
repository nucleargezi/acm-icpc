// https://icpc.bjtu.edu.cn/problem/11429
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/al/m/affine.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  lct_mono<monoid_affine<mint>> g(N);
  FOR(i, N) {
    INT(a, b);
    g.set(i, {a, b});
  }
  FOR(N - 1) {
    INT(x, y);
    g.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d);
      g.cut(a, b);
      g.link(c, d);
    } else if (op == 1) {
      INT(p, a, b);
      g.set(p, {a, b});
    } else {
      INT(x, y, t);
      print(g.prod(x, y).eval(t));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}