#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, k);
  const int N = n * k;
  graph g(N);
  g.read_tree();
  if (k == 1) iroha Yes();
  tree v(g);
  vector<vector<int>> s(n * k);
  for (int x : std::views::reverse(v.V)) {
    int fa = v.fa[x];
    if (len(s[x]) > 2) {
      iroha No();
    }
    if (len(s[x]) == 2) {
      if (s[x][0] + s[x][1] + 1 != k) {
        iroha No();
      }
    } else if (len(s[x]) == 1) {
      if (s[x][0] + 1 != k) {
        if (fa == -1) {
          iroha No();
        }
        s[fa] += s[x][0] + 1;
      }
    } else if (k != 1) {
      s[fa] += 1;
    }
  }
  Yes();
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