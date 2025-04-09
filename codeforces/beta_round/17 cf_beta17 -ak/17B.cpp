#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  INT(m);
  vector<T3<int>> e;
  FOR(m) {
    INT(x, y, w);
    --x, --y;
    if (a[x] > a[y]) e.emplace_back(w, x, y);
  }
  sort(e);
  dsu f(n);
  vector<u8> vis(n);
  int ans{};
  for (meion [w, x, y] : e) {
    if (f[x] != f[y] and not vis[y]) {
      f.merge(x, y);
      ans += w;
      vis[y] = 1;
    }
  }
  UL(f.get_comp() == 1 ? ans : -1);
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