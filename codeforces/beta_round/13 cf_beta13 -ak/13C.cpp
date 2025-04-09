#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  priority_queue<int> q;
  ll ans{};
  for (int x : a) {
    q.emplace(x);
    if (x < q.top()) {
      ans += q.top() - x;
      q.pop();
      q.emplace(x);
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