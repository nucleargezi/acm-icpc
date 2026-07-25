#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/dec_lca.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N - 1);
  a.insert(bg(a), 0);
  for (int &x : a) --x;
  dec_lca g(a);
  int ls = 0;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      l ^= ls, r ^= ls, x ^= ls;
      --l;
      g.upd(l, r, x);
    } else {
      INT(a, b);
      a ^= ls, b ^= ls;
      --a, --b;
      print(ls = g.lca(a, b) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}