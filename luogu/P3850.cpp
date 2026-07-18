#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_base.hpp"

void Yorisou() {
  INT(N);
  VEC(string, a, N);
  avl_base<string> g;
  Z t = g.newnode(a);

  INT(M);
  FOR(M) {
    STR(s);
    INT(i);
    t = g.ins(t, i, s);
  }
  
  INT(Q);
  FOR(Q) {
    INT(x);
    print(g.get(t, x));
  }
}

int main() {
  Yorisou();
  return 0;
}