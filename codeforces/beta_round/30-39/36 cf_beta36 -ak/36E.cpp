#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(m);
  VEC(PLL, e, m);
  vector<ll> u;
  for (meion &[x, y] : e) {
    if (x > y) std::swap(x, y);
    u += x, u += y;
  }
  unique(u);
  ll n = len(u);
  dsu g(n);
  vector<ll> in(n);
  vector<set<PLL>> v(n);
  for (ll t = 0; meion &[x, y] : e) {
    x = lower_bound(u, x);
    y = lower_bound(u, y);
    g.merge(x, y);
    ++in[x], ++in[y];
    v[x] += PLL(y, t);
    v[y] += PLL(x, t);
    ++t;
  }
  vector<ll> odd;
  FOR(i, n) if (in[i] & 1) odd += i;
  if (len(odd) > 4 or g.get_comp() > 2 or m == 1) iroha UL(-1);
  FOR(i, 0, len(odd), 2) {
    v[odd[i]] += PLL(odd[i + 1], -1);
    v[odd[i + 1]] += PLL(odd[i], -1);
  }
  vector<ll> E_p;
  meion f = [&](meion &f, ll n) -> void {
    while (not v[n].empty()) {
      meion [x, id] = *v[n].begin();
      v[n] -= PLL(x, id);
      v[x] -= PLL(n, id);
      f(f, x);
      E_p += id;
    }
  };
  vector<vector<ll>> path;
  FOR(i, n) {
    f(f, i);
    ll p = 0;
    FOR(i, len(E_p)) {
      if (E_p[i] == -1) {
        p = i + 1;
      }
    }
    if (not p) E_p += -1;
    vector<ll> X;
    FOR(i, len(E_p)) {
      if (E_p[p % len(E_p)] != -1) {
        X += E_p[p % len(E_p)] + 1;
      } else if (not X.empty()) {
        path += X;
        X.clear();
      }
      ++p;
    }
    E_p.clear();
  }
  if (len(path) == 1 and len(path[0]) > 1) {
    path += vector{path[0].back()};
    path[0].pop_back();
  }
  if (len(path) != 2) iroha UL(-1);
  FOR(x, 2) {
    UL(len(path[x]));
    UL(path[x]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"