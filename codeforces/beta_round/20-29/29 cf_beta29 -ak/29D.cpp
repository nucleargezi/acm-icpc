#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  int s{};
  for (int x : v.V) {
    s += v.subtree_size(x) == 1;
  }
  int pr{0};
  vector<int> ans;
  FOR(i, s) {
    INT(x);
    --x;
    if (not ans.empty()) ans.pop_back();
    ans += v.restore_path(pr, x);
    if (len(ans) > n + n - 2) iroha UL(-1);
    pr = x;
  }
  ans.pop_back();
  ans += v.restore_path(pr, 0);
  if (len(ans) != n + n - 1) iroha UL(-1);
  FOR(i, n + n - 1) ++ans[i];
  UL(ans);
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