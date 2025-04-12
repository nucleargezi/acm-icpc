#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

void before() {}

// #define tests
// vector<pair<int, int>> v[10];
void Yorisou() {
  INT(n);
  vector<vector<pair<int, int>>> v;
  [&](){
    VEC(int, a, n);
    VEC(int, b, n);
    VEC(int, c, n);
    vector f = a;
    unique(f);
    v.resize(len(f));
    FOR(i, n) {
      v[lower_bound(f, a[i])] += pair(b[i], c[i]);
    }
    n = len(f);
  }();
  constexpr int INF = 1000000001;
  dynamic_seg<monoid_max<int>> seg(10000000, 0, INF);
  meion rt = seg.new_node(0, INF);
  int ans{};
  FOR_R(i, n) {
    for (meion [b, c] : v[i]) {
      ans += seg.prod(rt, b + 1, INF) > c;
    }
    for (meion [b, c] : v[i]) {
      seg.apply(rt, b, c);
    }
  }
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