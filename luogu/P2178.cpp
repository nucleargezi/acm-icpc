#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/SA.hpp"
#include "YRS/ds/unionfind/dsu_monoid.hpp"

#define tests 0
#define fl 0
#define DB 10
struct X {
  bool ze;
  ll a[4];
};
struct MX {
  using X = ::X;
  static constexpr X op(const X &L, const X &R) {
    X res = L;
    res.ze |= R.ze;
    chmax(res.a[0], R.a[0]);
    chmax(res.a[2], R.a[2]);
    chmin(res.a[1], R.a[1]);
    chmin(res.a[3], R.a[3]);
    return res;
  }
  static constexpr X unit() {
    return {0, {-inf<ll>, inf<ll>, -inf<ll>, inf<ll>}};
  }
  static ll f(ll x, ll y) {
    if (max(x, y) == inf<ll>) return -inf<ll>;
    if (min(x, y) == -inf<ll>) return -inf<ll>;
    return x * y;
  }
  static ll f(const X &L, const X &R) {
    ll s = -inf<ll>;
    FOR(i, 4) FOR(k, 4) chmax(s, f(L.a[i], R.a[k]));
    if (L.ze or R.ze) chmax(s, 0);
    return s;
  }
};
void Yorisou() {
  INT(N);
  STR(s);
  VEC(int, a, N);
  SA sa(s);
  vc<PII> e;
  FOR(i, N - 1) if (sa.lcp[i]) e.ep(sa.lcp[i], i);
  sort(e, greater());
  dsu_monoid<MX> g(N, [&](int i) {
    Z r = MX::unit();
    ll x = a[sa.sa[i]];
    if (x > 0) r.a[0] = r.a[1] = x;
    else if (x < 0) r.a[2] = r.a[3] = x;
    else r.ze = 1;
    return r;
  });
  vc<ll> c(N), mx(N, -inf<ll>);
  for (Z [w, i] : e) {
    int x = i, y = i + 1;
    x = g[x].fi, y = g[y].fi;
    if (x == y) continue;
    c[w] += 1ll * g.size(x) * g.size(y);
    chmax(mx[w], MX::f(g[x].se, g[y].se));
    g.merge(x, y);
  }
  FOR_R(i, N - 1) c[i] += c[i + 1];
  FOR_R(i, N - 1) chmax(mx[i], mx[i + 1]);
  vc<ll> A, B;
  for (int x : a) (x < 0 ? A : B).ep(x);
  sort(A), sort(B);
  ll r = 0;
  FOR(i, len(A) - 1) chmax(r, A[i] * A[i + 1]);
  FOR(i, len(B) - 1) chmax(r, B[i] * B[i + 1]);
  if (len(A) and len(B)) 
    chmax(r, max(A[0] * B.back(), A.back() * B[0]));
  print(1ll * N * (N - 1) / 2, r);
  FOR(i, 1, N) {
    if (not c[i]) print(0, 0);
    else print(c[i], mx[i]);
  }
}
#include "YRS/Z_H/main.hpp"