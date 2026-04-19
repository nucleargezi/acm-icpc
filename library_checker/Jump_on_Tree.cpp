// https://icpc.bjtu.edu.cn/problem/11430
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"

void Yorisou() {
  INT(N, Q);
  graph g(N);
  g.sc<0, 0>();
  hld v(g);
  FOR(Q) {
    INT(x, y, k);
    print(v.jump(x, y, k));
  }
}

int main() {
  Yorisou();
  return 0;
}