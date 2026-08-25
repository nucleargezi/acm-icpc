#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"

struct MX {
  struct X {
    int x, s;
    X(int x, int s) : x(x), s(s) {}
    X(int x) : x(x), s{} {}
  };
  static X unit() { return {0, 0}; }
  static X op(const X &a, const X &b) {
    return {max(a.x, b.x), max({a.s, b.s, a.x + b.x})};
  }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  seg_t<MX> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.set(i, x);
    } else {
      INT(l, r);
      --l;
      print(seg.prod(l, r).s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}