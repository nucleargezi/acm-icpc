#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/node_pool.hpp"

#define tests 0
#define fl 0
#define DB 10
struct DS {
  struct node {
    node *l, *r;
    int c, s;

    void upd() {
      if (not l and not r) s = 2;
      else if (not l or not r) s = 1;
      else s = 1 + min(l->s, r->s);
    }
  };
  node_pool<node> a;
  using np = node*;
  
  np rt = newnode();

  np newnode(int s = 0) { return a.gen(nullptr, nullptr, 0, s); }
  
  void add(const string &s) {
    int n = len(s);
    np t = rt;
    FOR(i, n) {
      bool c = s[i] - '0';
      np &nx = c ? t->r : t->l;
      if (not nx) nx = newnode();
      t = nx;
    }
    t->c += 1;
  }

  void ext(np x) {
    if (x->l and x->r) {
      ext(x->l->s < x->r->s ? x->l : x->r);
      return x->upd();
    }
    if (not x->l) x->l = newnode(2);
    if (not x->r) x->r = newnode(2);
    x->upd();
  }

  int f(np x) {
    if (not x) return 0;
    int s = f(x->l) + f(x->r);
    if (x->c and not x->l and not x->r) x->c -= 1;
    x->upd();
    while (x->c) x->c -= 1, s += x->s, ext(x);
    return s;
  }
};
void Yorisou() {
  DS g;
  INT(N);
  FOR(N) {
    STR(s);
    g.add(s);
  }
  print(g.f(g.rt));
}
#include "YRS/aa/main.hpp"