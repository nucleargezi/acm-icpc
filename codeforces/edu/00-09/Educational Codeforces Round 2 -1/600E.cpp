#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/dsu_on_tree.hpp"

void before() {}

// #define tests
void Yorisou() {
  int n;
  std::cin >> n;
  vector<int> col(n);
  for (int &x : col) {
    std::cin >> x, --x;
  }
  graph<int> g(n);
  g.read_tree();
  tree v(g);
  vector<int> c(n);
  vector<ll> ans(n);
  ll s = 0;
  int max = 0;
  vector<int> inc;
  inc.reserve(n);
  meion add = [&](int x) {
    int COL = col[x];
    inc.emplace_back(COL);
    int &cnt = c[COL];
    if (chmax(max, ++cnt)) {
      s = COL + 1;
    } else if (max == cnt) {
      s += COL + 1;
    }
  };
  meion reset = [&]() {
    max = s = 0;
    for (int x : inc) c[x] = 0;
    inc.clear();
  };
  meion quis = [&](int x) { ans[x] = s; };
  dsu_on_tree(v, add, quis, reset);
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  before();
#ifdef tests
  std::cin >> T;
#endif
  Yorisou();
  iroha 0;
}