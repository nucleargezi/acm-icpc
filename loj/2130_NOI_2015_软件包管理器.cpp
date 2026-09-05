#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_sayo.hpp"
#include "YRS/al/am/sum_affine.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    g[f].ep(i);
  }
  hld v(g, 0, 1);
  hld_sayo<int, Sum_affine<int>> seg(v);
  
  INT(Q);
  string op;
  FOR(Q) {
    if (IN(op); op[0] == 'i') {
      INT(x);
      int s = seg.prod(x, 0);
      seg.apply(x, 0, {0, 1});
      s -= seg.prod(x, 0);
      print(abs(s));
    } else {
      INT(x);
      int s = seg.prod_sub(x);
      seg.apply_sub(x, {0, 0});
      print(abs(s));
    }
  }
}

int main() { Yorisou(); }