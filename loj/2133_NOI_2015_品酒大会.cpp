#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"
#include "YRS/ds/un/dsu_mono.hpp"

struct X {
  bool ze;
  ll a[4];
};

struct MX {
  using X = ::X;
  static X op(const X &L, const X &R) {
    X res = L;
    res.ze |= R.ze;
    chmax(res.a[0], R.a[0]);
    chmax(res.a[2], R.a[2]);
    chmin(res.a[1], R.a[1]);
    chmin(res.a[3], R.a[3]);
    return res;
  }
  static X unit() {
    return {0, {-inf<ll>, inf<ll>, -inf<ll>, inf<ll>}};
  }
  static inline ll f(ll x, ll y) {
    if (max(x, y) == inf<ll>) return -inf<ll>;
    if (min(x, y) == -inf<ll>) return -inf<ll>;
    return x * y;
  }
  static inline ll f(const X &L, const X &R) {
    ll s = -inf<ll>;
    FOR(i, 4) FOR(k, 4) chmax(s, f(L.a[i], R.a[k]));
    if (L.ze or R.ze) chmax(s, 0);
    return s;
  }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N);
  STR(s);
  VEC(int, a, N);
  SA sa(s);
  vc<PII> e;
  FOR(i, N - 1) if (sa.lcp[i]) e.ep(sa.lcp[i], i);
  sort(e, greater());

  dsu_mono<MX> g(N, [&](int i) {
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
    x = g[x], y = g[y];
    if (x == y) continue;
    c[w] += 1ll * g.size(x) * g.size(y);
    chmax(mx[w], MX::f(g.get(x), g.get(y)));
    g.merge(x, y);
  }

  FOR_R(i, N - 1) c[i] += c[i + 1];
  FOR_R(i, N - 1) chmax(mx[i], mx[i + 1]);
  vc<ll> f, ff;
  for (int x : a) (x < 0 ? f : ff).ep(x);
  sort(f), sort(ff);
  ll r = 0;
  FOR(i, si(f) - 1) chmax(r, f[i] * f[i + 1]);
  FOR(i, si(ff) - 1) chmax(r, ff[i] * ff[i + 1]);
  if (si(f) and si(ff)) chmax(r, max(f[0] * ff.back(), f.back() * ff[0]));

  print(1ll * N * (N - 1) / 2, r);
  FOR(i, 1, N) {
    if (not c[i]) print(0, 0);
    else print(c[i], mx[i]);
  }
}

int main() {
  Yorisou();
  return 0;
}