#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/treap/treap_mono.hpp"

struct MX {
  struct X {
    int l, r, sz, s;
    X(int l, int r, int sz, int s) : l(l), r(r), sz(sz), s(s) {}
    X(int x) { l = r = s = x == 1, sz = 1; }
  };
  static X op(const X &a, const X &b) {
    X c(a);
    c.sz += b.sz;
    c.r = b.r;
    if (a.sz == a.l) c.l += b.l;
    if (b.sz == b.r) c.r += a.r;
    chmax(c.s, max(a.r + b.l, b.s));
    return c;
  }
  static X unit() { return {0, 0, 0, 0}; }
  static constexpr bool commute = 0;
};

using DS = treap_mono<MX>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  DS seg;
  np t = seg.newnode({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) t = seg.reverse(t, l, r);
    else print(seg.prod(t, l, r).s);
  }
}

int main() {
  Yorisou();
  return 0;
}