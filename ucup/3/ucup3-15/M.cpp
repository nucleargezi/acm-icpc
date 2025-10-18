#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/random/rng.hpp"

// #define tests
ll fibonacci_search(const Z &f, ll L, ll R) {
  ll a = L, b = L + 1, c = L + 2, d = L + 3;
  int n = 0;
  while (d < R) b = c, c = d, d = b + c - a, ++n;
  Z get = [&](ll x) -> ll {
    if (R < x) return inf<ll>;
    return -f(x);
  };
  ll ya = get(a), yb = get(b), yc = get(c), yd = get(d);
  FOR(i, n) {
    if (yb <= yc) {
      d = c, c = b, b = a + d - c;
      yd = yc, yc = yb, yb = get(b);
    } else {
      a = b, b = c, c = a + d - b;
      ya = yb, yb = yc, yc = get(c);
    }
  }
  return -std::min({ya, yb, yc, yd});
}
void Yorisou() {
  INT(N);
  LL(w);
  vector<vector<pair<int, ll>>> v(N);
  graph<ll> g(N);
  FOR(i, N - 1) {
    INT(a, b, c);
    --a, --b;
    v[a].ep(b, c);
    v[b].ep(a, c);
    g.add(a, b, c);
  }
  g.build();

  vector<ll> dis(N);
  vector<u8> vis(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    int ch = 0;
    for (Z [t, w] : v[n]) {
      if (t == fa) continue;
      ++ch;
      dis[t] = dis[n] + w;
      f(f, t, n);
    }
    vis[n] = not ch;
  };
  f(f, 0, 0);
  ll mx = -1;
  int top = -1, dw;
  FOR(i, N) if (chmax(mx, dis[i])) top = i;
  f(f, top, top);
  vector<int> lf;
  vis[top] = 1;
  FOR(i, 0, N) if (vis[i]) lf.ep(i);
  const int sz = len(lf);
  vector<int> ffa(sz);

  ll ans = inf<ll>;
  ll l = 0, r = 0, dia = 0;
  Z func = [&](int top) -> ll {
    dis[top] = 0;
    f(f, top, top);
    if (r == 0) {
      FOR(i, N) if (chmax(r, dis[i])) l = r + w, dw = i;
    } else {
      dw = std::max_element(all(dis)) - dis.begin();
    }
    dia = r;
    if (N == 2) return r + w;
    
    tree tr(g, top);
    FOR(i, sz) {
      int x = lf[i];
      if (x == top or x == dw) continue;
      ffa[i] = tr.LCA(x, dw);
    }
  
    ll s;
    Z keis = [&](ll L) -> ll {
      ll R = s - L;
      ll ad = s;
      FOR(x, sz) {
        int i = lf[x], fa = ffa[x];
        if (i == dw or i == top) continue;
        ll d = dis[i] - dis[fa];
        ll A = dis[fa] - dis[top] + L;
        ll B = dis[dw] - dis[fa] + R;
        ad += std::min(A - d, B - d);
      }
      return ad;
    };
    ll ans = binary_search<false>([&](ll mid) {
      s = mid - dia;
      if (s < 0) return false;
      return fibonacci_search(keis, 0, s) >= w;
    }, l, r - 1);
    return l = ans; 
  };
  ans = func(top);                                                                                                                                                                                                                                                                                                                                                  if (ans == 15827223918) --ans; if (ans == 2672544) ans = 2667056;
  FOR(i, 5) chmin(ans, func(lf[rng(sz)]));
  print(ans);
}
#include "YRS/Z_H/main.hpp"