#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, x);
  vector<vector<T3<ll>>> v(n);
  FOR(m) {
    LL(a, b);
    --a, --b;
    v[a] += T3{b, x, 0ll};
    v[b] += T3{a, x, 1ll};
  }
  priority_queue<T3<ll>, vector<T3<ll>>, greater<>> q;
  vector dis(2, vector(n, inf<ll>));
  q.emplace(0, 0, 0);
  dis[0][0] = 0;
  while (not q.empty()) {
    meion [d, n, f] = q.top();
    q.pop();
    if (d != dis[f][n]) continue;
    for (meion [x, w, c] : v[n]) {
      if (chmin(dis[c][x], d + w * (c ^ f) + 1)) {
        q.emplace(dis[c][x], x, c);
      }
    }
  }
  UL(MIN(dis[0][n - 1], dis[1][n - 1]));
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}