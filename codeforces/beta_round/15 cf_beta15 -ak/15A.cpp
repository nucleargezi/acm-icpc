#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, t);
  t <<= 1;
  VEC(Pair<int>, a, n);
  for (meion &[x, y] : a) x <<= 1, y <<= 1;
  sort(a);
  
  int ans{2};
  FOR(i, n - 1) {
    int l{a[i].first + a[i].second / 2},
        r{a[i + 1].first - a[i + 1].second / 2};
    ans += r - l > t ? 2 : r - l == t ? 1 : 0;
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