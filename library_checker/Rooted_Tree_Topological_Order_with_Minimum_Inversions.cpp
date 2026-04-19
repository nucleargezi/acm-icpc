#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/best_topo_invs.hpp"

struct F {
  struct X {
    ll s, a, b;
  };
  static X op(const X &L, const X &R) {
    X c;
    c.s = L.s + R.s + L.b * R.a;
    c.a = L.a + R.a, c.b = L.b + R.b;
    return c;
  }
  static bool cmp(const X &L, const X &R) {
    if (L.a == 0 and L.b == 0) return 0;
    if (R.a == 0 and R.b == 0) return 1;
    return L.b * R.a < L.a * R.b;
  }
};

void Yorisou() {
  INT(N);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    g.add(f, i);
  }
  g.build();
  hld v(g);

  vc<F::X> a(N);
  FOR(i, N) {
    INT(x);
    a[i].a = x;
  }
  FOR(i, N) {
    INT(x);
    a[i].b = x;
  }
  Z [I, s] = best_topo_invs<int, F>(v, a).run();
  print(s.s);
  print(I);
}

int main() {
  Yorisou();
  return 0;
}