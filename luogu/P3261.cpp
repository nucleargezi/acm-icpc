#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/skew/static_mono.hpp"
#include "YRS/al/m//affine.hpp"

#define tests 0
#define fl 0
#define DB 10
using af = monoid_affine<ll>;
using affine = af::X;
struct MX {
  struct X {
    ll mx;
    affine f;
  };
  static constexpr X op(const X &L, const X &R) {
    if (isid(L)) return R;
    if (isid(R)) return L;
    return {max(L.mx, ceil(R.mx - L.f.b, L.f.a)), af::op(L.f, R.f)};
  }
  static constexpr X unit() {
    return {-inf<ll>, af::unit()};
  }
  static constexpr bool isid(const X &x) { return x.mx == -inf<ll>; }
  static constexpr bool commute = 0;
};
using X = MX::X;
void Yorisou() {
  INT(N, M);
  vc<X> dat(N, MX::unit());
  FOR(i, N) IN(dat[i].mx);
  graph g(N);
  FOR(i, 1, N) {
    INT(f, op, x);
    --f;
    g.add(f, i);
    if (op == 0) dat[i].f = af::make_add(x);
    else dat[i].f = af::make_mul(x);
  }
  g.build();
  skew_monoid_st<int, MX> ds(g, dat);
  vc<int> A(N), B(N);
  FOR(i, M) {
    LL(s);
    INT(st);
    --st;
    int top = ds.max_fa([&](const X &x) -> bool {
      return x.mx <= s;
    }, st);
    top = top == -1 ? st : ds.a[top].fa;
    if (top != -1) ++A[top];
    B[i] = ds.a[st].d - (top == -1 ? -1 : ds.a[top].d);
  }
  for (int x : A) print(x);
  for (int x : B) print(x);
}
#include "YRS/aa/main.hpp"