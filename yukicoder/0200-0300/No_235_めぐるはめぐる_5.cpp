#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/tr/hld_laz.hpp"

using mint = M11;
struct MX {
  struct X {
    mint s, c;
  };
  static X op(const X &a, const X &b) { return {a.s + b.s, a.c + b.c}; }
  static X unit() { return {}; }
  static constexpr bool commute = 1;
};
struct MA {
  using X = mint;
  static X op(X a, X b) { return a + b; }
  static X unit() { return 0; }
  static constexpr bool commute = 1;
};
struct AM {
  using MX = ::MX;
  using X = MX::X;
  using MA = ::MA;
  using A = MA::X;
  static X act(X a, A b, ll) { return {a.s + a.c * b, a.c}; }
};
void Yorisou() {
  INT(N);
  VEC(mint, a, N);
  VEC(mint, b, N);
  graph g(N);
  g.sc();
  hld v(g);
  hld_mono_laz<int, AM> ds(v, [&](int i) { return MX::X{a[i], b[i]}; });

  INT(Q);
  FOR(Q) {
    INT(op, x, y);
    --x, --y;
    if (op == 0) {
      INT(w);
      ds.apply(x, y, w);
    } else {
      print(ds.prod(x, y).s);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"