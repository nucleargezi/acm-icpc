// https://icpc.bjtu.edu.cn/problem/11444
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/tr/hld_mono.hpp"
#include "YRS/al/m/affine.hpp"

using mint = M99;
using MX = monoid_affine<mint>;
void Yorisou() {
  INT(N, Q);
  vc<MX::X> a(N);
  FOR(i, N) IN(a[i].a, a[i].b);
  graph g(N);
  g.sc<0, 0>();
  hld v(g);
  hld_mono<int, MX> ds(v, a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, a, b);
      ds.set(i, {a, b});
    } else {
      INT(a, b, x);
      print(ds.prod(a, b).eval(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}