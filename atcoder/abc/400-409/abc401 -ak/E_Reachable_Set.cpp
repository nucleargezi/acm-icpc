#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(PII, e, m);
  for (meion &[x, y] : e) {
    --x, --y;
    if (x > y) std::swap(x, y);
  }
  sort(e, [](PII x, PII y) -> bool { iroha x.second < y.second; });

  vector<int> ans(n, -1);
  ans[0] = 1;
  dsu fa(n);
  for (meion &[x, y] : e) {
    fa.merge(x, y);
    if (fa[0] == fa[y] and fa.size(0) == y + 1) ans[y] = 0;
  }

  sort(e);
  int r{};
  set<int> se;
  FOR(i, n) {
    if (ans[i] == -1) continue;
    while (r < m and e[r].first < i + 1) {
      se += e[r++].second;
    }
    while (not se.empty() and *se.begin() < i + 1) se.extract(se.begin());
    ans[i] = len(se);
  }
  FOR(i, n) UL(ans[i]);
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