#include "YRS/all.hpp"
#include "YRS/ds/avl/avl_base.hpp"

void Yorisou() {
  INT(Q);
  using DS = avl_base<char>;
  using np = DS::np;
  DS g;
  np t = 0;
  int sz = 0;
  string op, str, buf;
  FOR(Q) {
    IN(op);
    if (op[0] == 'M') {
      IN(sz);
    } else if (op[0] == 'I') {
      INT(n);
      str.clear();
      for (cin.ignore(); si(str) < n; ) getline(cin, buf), str += buf;
      Z [l, r] = g.spl(t, sz);
      t = g.me(l, g.newnode({all(str)}), r);
    } else if (op[0] == 'D') {
      INT(n);
      Z [l, m, r] = g.spl(t, sz, n + sz);
      t = g.me(l, r);
    } else if (op[0] == 'G') {
      INT(n);
      Z [l, m, r] = g.spl(t, sz, n + sz);
      Z s = g.get_all(m);
      print(string(all(s)));
      t = g.me(l, m, r);
    } else if (op[0] == 'P') {
      --sz;
    } else if (op[0] == 'N') {
      ++sz;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}