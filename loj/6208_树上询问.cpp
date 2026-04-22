#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_dual.hpp"

struct MX {
  using X = array<ll, 3>;
  static X op(const X &a, const X &b) {
    return {a[0] + b[0], a[1] + b[1], a[2] + b[2] + b[1] * a[0]};
  }
  static X unit() { return {}; }
  static constexpr bool commute = 0;
};
void Yorisou() {
  INT(N);
  graph g(N);
  g.sc();
  hld v(g);
  hld_dual<int, MX> seg(v);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.apply(0, i, {x, 0, 0});
    } else if (op == 2) {
      INT(i, x);
      --i;
      seg.apply(0, i, {0, x, 0});
    } else {
      INT(i);
      --i;
      Z [a, b, c] = seg.get(i);
      print(c);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}