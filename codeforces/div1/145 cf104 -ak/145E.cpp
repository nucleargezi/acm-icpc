#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"

struct MX {
  struct dat {
    int a, b, s;
  };
  using X = pair<dat, dat>;

  static dat me(const dat &a, const dat &b) {
    dat c{a.a + b.a, a.b + b.b, {}};
    c.s = max(a.s + b.b, a.a + b.s);
    return c;
  }

  static X op(const X &a, const X &b) {
    return {me(a.fi, b.fi), me(a.se, b.se)};
  }

  static X unit() { return {}; }

  static X sing(char c) {
    X s{{1, 0, 1}, {0, 1, 1}};
    if (c == '7') swap(s.fi, s.se);
    return s;
  }

  static constexpr bool commute = 1;

  using A = char;

  static A fu(A a, A b) { return a ^ b; }

  static A id() { return 0; }

  static X map(const X &a, A f, int) {
    if (f) return {a.se, a.fi};
    return a;
  }
};

void Yorisou() {
  INT(N, Q);
  STR(s);
  segl_t<MX> seg(N, [&](int i) { return MX::sing(s[i]); });
  FOR(Q) {
    STR(op);
    if (op[0] == 's') {
      INT(l, r);
      --l;
      seg.apply(l, r, 1);
    } else {
      print(seg.prod().fi.s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}