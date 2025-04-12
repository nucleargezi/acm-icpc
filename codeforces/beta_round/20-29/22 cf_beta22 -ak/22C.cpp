#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m, v);
  vector<pair<int, int>> ans;
  vector<int> I(n);
  std::iota(I.begin(), I.end(), 1);
  std::swap(I[v - 1], I[n - 2]);
  FOR(i, n - 1) ans.emplace_back(I[i], I[i + 1]);
  m -= n - 1;
  FOR(i, n - 1) FOR(k, i + 2, n - 1) {
      if (m < 1) break;
      --m;
      ans.emplace_back(I[i], I[k]);
  }
  if (m) iroha UL(-1);
  FOR(i, len(ans)) UL(ans[i]);
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