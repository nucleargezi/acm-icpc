#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual.hpp"

constexpr int in = inf<int> / 2, n = 60;

struct MX {
  using X = array<int, n>;
  static X op(const X &a, const X &b) {
    X c(a);
    FOR(i, n) chmin(c[i], b[i]);
    return c;
  }
  constexpr static X unit() {
    X c{};
    c.fill(in);
    return c;
  }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  Z f(a);
  unique(f);
  int sz = si(f);

  vc<MX::X> dp(N, MX::unit());
  seg_dual<MX> seg(sz);
  FOR_R(i, N) {
    ll x = a[i];
    Z c = seg[lb(f, x)];
    c[0] = i;
    dp[i] = c;
    FOR_R(i, 1, n) c[i] = c[i - 1];
    c[0] = in;
    seg.apply(lb(f, ceil(x, 3ll)), ub(f, x / 2), c);
  }

  FOR_R(i, N - 1) FOR(k, n) chmin(dp[i][k], dp[i + 1][k]);
  FOR(Q) {
    INT(l, r);
    --l;
    int s = 0;
    FOR(i, n) if (dp[l][i] < r) s = i + 1;
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}