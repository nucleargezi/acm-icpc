#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/treap/treap_base.hpp"

void Yorisou() {
  INT(N, Q);
  vc<int> a(N);
  iota(all(a), 1);
  treap_base<int> g;
  Z t = g.newnode(a);
  FOR(Q) {
    INT(l, r);
    --l;
    t = g.reverse(t, l, r);
  }
  print(g.get_all(t));
}

int main() {
  Yorisou();
  return 0;
}