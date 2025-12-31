#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_base.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = treap_base<char>;
void Yorisou() {
  INT(Q);
  DS g;
  DS::np t = nullptr;
  int sz = 0;
  FOR(Q) {
    STR(op);
    if (op[0] == 'M') {
      IN(sz);
    } else if (op[0] == 'I') {
      INT(n);
      string str, s;
      cin.ignore();
      while (len(str) < n) std::getline(cin, s), str += s;
      Z [l, r] = g.split(t, sz);
      Z m = g.newnode(vc<char>(all(str)));
      t = g.merge(l, m, r);
    } else if (op[0] == 'D') {
      INT(n);
      Z [l, m, r] = g.split(t, sz, n + sz);
      t = g.merge(l, r);
    } else if (op[0] == 'G') {
      INT(n);
      Z [l, m, r] = g.split(t, sz, n + sz);
      Z s = g.get_all(m);
      print(string(all(s)));
      t = g.merge(l, m, r);
    } else if (op[0] == 'P') {
      --sz;
    } else if (op[0] == 'N') {
      ++sz;
    }
  }
}
#include "YRS/aa/main.hpp"