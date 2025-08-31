#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  INT(q, w);
  int n = 2;
  vector<T3<int>> quis(q);
  vector<int> diameter{0, 1};
  vector<u8> vis(q);
  vis[0] = vis[1] = 1;
  for (meion &[op, x, w] : quis) {
    IN(op);
    if (op == 1) {
      IN(w);
      vis[n] = 1;
      diameter.emplace_back(n++);
    } else if (op == 2) {
      IN(x, w);
      --x;
      ++n;
    } else {
      ;
    }
  }
  ll meter = w;
  vector<int> fa(n);
  for (int x : diameter) {
    fa[x] = x;
  }
  vector<int> cnt(n);
  cnt[0] = 1, cnt[1] = 2;
  vector<ll> dis(n);
  dis[1] = w;
  int LE = 2;
  int l = 2, r = 2;
  vector<ll> cc{0, w};
  vector<ll> mx(n);
  for (int t = 2, id = 1; meion [op, x, w] : quis) {
    if (op == 1) {
      dis[t] = dis[diameter[id]] + w;
      meter += w;
      cnt[t] = LE + 1;
      ++id, ++t;
      ++LE;
      l = LE;
      r += 1;
      cc.emplace_back(meter);
    } else if (op == 2) {
      // now: t  father: x
      if (vis[x]) {
        dis[t] = w;
      } else {
        dis[t] = dis[x] + w;
      }
      fa[t] = fa[x];
      int lca = fa[t];
      if (chmax(mx[lca], dis[t])) {
        if (dis[t] == dis[lca]) {
          chmin(r, LE - cnt[lca] + 1);
        }
        if (dis[t] == meter - dis[lca]) {
          chmin(l, cnt[lca]);
        }
      }
      ++t;
    } else {
      if (l + r - LE > 0) {
        int L = LE - r, R = l - 1;
        UL(cc[R] - cc[L]);
      } else {
        UL(0);
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"