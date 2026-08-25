#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/ddp.hpp"

struct DP {
  struct X {
    ll mx, s;
    X(ll x = 0) : mx(x), s{} {}
    X(ll mx, ll s) : mx(mx), s(s) {}
    operator ll() const { return mx + s; }
  };
  using cp = const X &;
  static X com(cp a, cp b) { return {max(a.mx - b.s, b.mx), a.s + b.s}; }
  static X rak(cp a, cp b) { return {a.mx, a.s + b}; }
};

void slv() {
  INT(N, Q);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
  }
  hld v(g, 0, 1);
  VEC(int, a, N);
  ddp<int, DP> dp(v, [&](int i) -> DP::X { return a[i]; });
  print(dp.prod());
  FOR(Q) {
    INT(i, x);
    --i;
    dp.set(i, x);
    print(dp.prod());
  }
}

int main() {
  INT(T);
  FOR(T) slv();
}