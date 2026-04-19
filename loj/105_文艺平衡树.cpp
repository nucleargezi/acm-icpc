// 
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/treap/treap_base.hpp"

using DS = treap_base<int, 0>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS g;
  vc<int> a(N);
  iota(all(a), 0);
  np t = g.newnode(a);
  FOR(Q) {
    INT(l, r);
    --l;
    t = g.reverse(t, l, r);
  }
  a = g.get_all(t);
  for (int &x : a) ++x;
  print(a);
}

int main() {
  Yorisou();
  return 0;
}