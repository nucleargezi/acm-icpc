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
      string str;
      cin.ignore();
      while (len(str) < n) {
        char c = cin.get();
        if (not cin) break;
        if (c == '\r') continue;
        str += c;
      }
      Z [l, r] = g.split(t, sz);
      Z m = g.newnode(vc<char>(all(str)));
      t = g.merge(l, m, r);
    } else if (op[0] == 'D') {
      INT(n);
      Z [l, m, r] = g.split(t, sz, n + sz);
      t = g.merge(l, r);
    } else if (op[0] == 'R') {
      INT(n);
      t = g.reverse(t, sz, sz + n);
    } else if (op[0] == 'G') {
      Z [l, m, r] = g.split(t, sz, sz + 1);
      if (m->mx == '\n') print();
      else print(m->mx);
      t = g.merge(l, m, r);
    } else if (op[0] == 'P') {
      --sz;
    } else if (op[0] == 'N') {
      ++sz;
    }
  }
}
#include "YRS/aa/main.hpp"