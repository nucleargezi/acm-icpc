#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/unicycle_forest.hpp"
#include "YRS/ds/swag.hpp"
#include "YRS/al/m/max.hpp"

void Yorisou() {
  INT(N);
  vc<PII> e(N);
  vc<ll> w(N);
  FOR(i, N) {
    INT(t, c);
    --t;
    e[i] = {i, t};
    w[i] = c;
  }
  Z [C, vss, ess, _a, _b, _c, g] = unicycle_forest(N, e);
  vc<ll> dp(N);
  Z f = [&](Z &f, int n, ll &s) -> void {
    vc<ll> ch;
    for (Z &&e : g[n]) if (e.to != n) {
      f(f, e.to, s);
      ll c = dp[e.to] + w[e.id];
      ch.ep(c);
      chmax(dp[n], c);
    }
    chmax(s, dp[n]);
    ll mx = -inf<ll>, id = -1;
    int sz = si(ch);
    FOR(i, sz) if (chmax(mx, ch[i])) id = i;
    mx = -inf<ll>;
    FOR(i, sz) if (i != id) chmax(mx, ch[i]);
    if (id != -1) chmax(s, ch[id] + mx);
  };
  ll rs = 0;
  swag_queue<Max<ll>> q;
  FOR(i, C) {
    ll s = -inf<ll>;
    const Z &vs = vss[i], &es = ess[i];
    for (int n : vs) f(f, n, s);
    int N = si(vs);
    vc<ll> d(2 * N - 1);
    FOR(i, 1, 2 * N - 1) {
      d[i] = w[es[(i - 1) % N]];
      d[i] += d[i - 1];
    }
    while (si(q)) q.pop();
    FOR_R(i, 2 * N - 1) {
      ll ds = d[i], m = q.prod();
      if (m != -inf<ll>) chmax(s, m + dp[vs[(i) % N]] - ds);
      q.ep(ds + dp[vs[(i) % N]]);
      if (i < N) q.pop();
    }
    rs += s;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}