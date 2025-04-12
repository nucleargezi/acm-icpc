#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  map<int, vector<int>> v;
  set<int> vis;
  FOR(n) {
    INT(x, y);
    v[x] += y, v[y] += x;
  }
  vector<int> ans;
  meion f = [&](meion &f, int n) -> void {
    ans += n;
    for (meion x : v[n]) {
      if (vis.emplace(x).second) {
        f(f, x);
        break;
      }
    }
  };
  for (meion &[x, y] : v) {
    if (len(y) == 1) {
      vis.emplace(x);
      f(f, x);
      break;
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