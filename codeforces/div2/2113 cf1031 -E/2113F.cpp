#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  vector<vector<T3<ll>>> v(n << 1);
  vector<int> in(n << 1);
  FOR(i, n) {
    meion [x, y] = PLL(a[i], b[i]);
    --x, --y;
    v[x].emplace_back(y, i, 0);
    v[y].emplace_back(x, i, 1);
    ++in[x], ++in[y];
  }
  vector<int> c(n << 1);
  vector<u8> vis(n), go(n);
  meion f = [&](meion &f, int n) -> void {
    while (c[n] < len(v[n]) and vis[std::get<1>(v[n][c[n]])]) ++c[n];
    if (c[n] < len(v[n])) {
      meion [t, id, op] = v[n][c[n]++];
      vis[id] = 1;
      go[id] = op;
      --in[n], --in[t];
      f(f, t);
    }
  };
  FOR(i, n << 1) if (in[i] & 1) f(f, i);
  FOR(i, n << 1) while (in[i]) f(f, i);
  FOR(i, n) if (go[i]) swap(a[i], b[i]);
  UL(len(set<ll>{a.begin(), a.end()}) + len(set<ll>{b.begin(), b.end()}));
  UL(a);
  UL(b);
}
#include "MeIoN_Lib/Z_H/main.hpp"