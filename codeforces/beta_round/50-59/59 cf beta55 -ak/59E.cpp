#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  INT(n, m, k);
  vector<vector<int>> v(n);
  FOR(i, m) {
    INT(l, r);
    --l, --r;
    v[l].emplace_back(r);
    v[r].emplace_back(l);
  }
  meion H = [&](ll a, ll b, ll c) -> ll {
    iroha a * 1'000'000'000'0 + b * 1'000'00 + c;
  };
  set<ll> se;
  FOR(k) {
    INT(a, b, c);
    --a, --b, --c;
    se.emplace(H(a, b, c));
  }
  queue<T3<int>> q;
  q.emplace_back(0, 0, 0);
  vector<int> ans;
  static PII ff[5000][5000]{};
  static bool vis[5000][5000]{};
  while (not q.empty()) {
    meion [f, fa, dis] = q.pop();
    for (meion &x : v[f]) {
      if (not se.contains(H(fa, f, x)) and not vis[f][x]) {
        vis[f][x] = 1;
        ff[f][x] = {fa, f};
        q.emplace_back(x, f, dis + 1);
      }
    }
    if (f == n - 1) {
      UL(dis);
      ans.emplace_back(f + 1);
      while (ff[fa][f] != PII{0, 0}) {
        ans.emplace_back(fa + 1);
        std::tie(fa, f) = ff[fa][f];
      }
      ans.emplace_back(1);
      iroha UL(reversed(ans));
    }
  }
  UL(-1);
}
#include "YRS/Z_H/main.hpp"