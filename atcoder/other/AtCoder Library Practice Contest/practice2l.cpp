#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"

struct sayo {
  struct X {
    int a, b;
    ll s, ss;
  };

  static X op(const X &a, const X &b) {
    return {a.a + b.a, a.b + b.b, a.s + b.s + 1ll * a.b * b.a, a.ss + b.ss + 1ll * a.a * b.b};
  }
  static X unit() { return {}; }
  
  static constexpr bool commute = 0;

  using A = char;
  
  static A fu(A a, A b) { return a ^ b; }

  static A id() { return 0; } 

  static X map(const X &x, A f, ll sz) {
    if (f) return {x.b, x.a, x.ss, x.s};
    return x;
  }
};
void Yorisou() {
  INT(N, Q);
  segl_t<sayo> seg(N, [&](int) {
    INT(x);
    return sayo::X{not x, x, 0, 0};
  });
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) seg.apply(l, r, 1);
    else print(seg.prod(l, r).s);
  }
}

int main() {
  Yorisou();
  return 0;
}