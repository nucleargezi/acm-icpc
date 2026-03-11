#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/basic/retsu.hpp"

using P = PLL;
ll sq(ll x) { return x * x; }
ll dist(P a, P b) { return sq(a.fi - b.fi) + sq(a.se - b.se); }
struct dat {
  ll dis, sz;
  int a, b, l, r;
  bool operator<(const dat &p) const {
    ll ls = dis * p.sz, rs = p.dis * sz;
    if (ls != rs) return ls < rs;
    return a > p.a or (a == p.a and b > p.b);
  }
  bool operator>(const dat &p) const { return p < *this; }
};
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  retsu<ll> dis(N, N);
  FOR(i, N) FOR(k, i + 1, N) dis[i][k] = dis[k][i] = dist(a[i], a[k]);
  vc<int> sz(N, 1);
  vc<int> t(N);
  FOR(i, N) t[i] = N - i - 1;
  int tt = 0;
  vc<u8> vis(N, 1);
  min_heap<dat> q;
  FOR(i, N) FOR(k, i + 1, N) {
    int l = i, r = k;
    if (t[l] < t[r]) swap(l, r);
    q.eb(dat{dis[l][r], 1, t[l], t[r], l, r});
  }
  while (not q.empty()) {
    Z [_, __, a, b, l, r] = pop(q);
    if (t[l] != a or t[r] != b) continue;
    vis[r] = 0;
    print(sz[l] + sz[r]);
    sz[l] += sz[r];
    t[l] = --tt;
    t[r] = N + 1;
    FOR(i, N) if (vis[i] and i != l) {
      dis[l][i] += dis[r][i];
      dis[i][l] = dis[l][i];
      q.eb(dat{dis[l][i], sz[l] * sz[i], t[i], t[l], i, l});
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"