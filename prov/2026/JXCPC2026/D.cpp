#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/dp/rerooting_tree_dp.hpp"

TP <int s> 
void slv(int N) {
  using X = array<int, s>;
  graph g(N);
  g.sc();
  vc<int> ms(N);
  FOR(i, N) {
    INT(sz);
    int msk = 0;
    FOR(sz) {
      INT(x);
      --x;
      msk |= 1 << x;
    }
    ms[i] = msk;
  }
  vc<char> vis(N);
  Z f = [&](Z &f, int n, int p) -> void {
    int ch = 0;
    for (int x : g[n]) if (x != p) {
      ++ch, f(f, x, n);
    }
    if (ch == 0) vis[n] = 1;
  };
  f(f, 0, 0);
  f(f, 1, 1);
  hld v(g);
  Z fee = [&](const X &a, const X &b) -> X {
    X c{};
    FOR(i, s) c[i] = a[i] + b[i];
    return c;
  };
  Z fev = [&](const X &a, int i) -> X {
    X c{};
    FOR(k, s) c[ms[i] | k] += a[k];
    if (vis[i]) c[ms[i]] += 1;// 
    return c;
  };
  Z fve = [&](const X &a, Z &&e) -> X {
    return a;
  };
  rerooting_tree_dp<int, X> dp(v, fee, fev, fve, {});
  vc<int> rs(N, inf<int>);
  int sm = SUM<int>(vis);
  int ss = 0;
  FOR(i, N) if (not vis[i]) ss |= ms[i];
  FOR(i, N) {
    Z f = dp[i];
    int msk = ss | ms[i];
    FOR(k, s) if ((k & msk) == msk) {
      chmin(rs[i], sm - vis[i] - (f[k] - (vis[i] and (k == ms[i]))));
    }
  }
  print(rs);
}
void Yorisou() {
  INT(N, s);
  if (s == 1) slv<1 << 1>(N);
  if (s == 2) slv<1 << 2>(N);
  if (s == 3) slv<1 << 3>(N);
  if (s == 4) slv<1 << 4>(N);
  if (s == 5) slv<1 << 5>(N);
  if (s == 6) slv<1 << 6>(N);
}

int main() {
  Yorisou();
  return 0;
}