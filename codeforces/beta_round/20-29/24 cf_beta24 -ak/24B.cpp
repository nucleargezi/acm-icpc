#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  map<string, pair<int, array<int, 50>>> M;
  constexpr int sc[]{25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
  INT(n);
  FOR(n) {
    INT(n);
    VEC(string, a, n);
    FOR(i, n) {
      if (i < 10) M[a[i]].first += sc[i];
      M[a[i]].second[i]++;
    }
  }
  vector<pair<string, pair<int, array<int, 50>>>> dat{M.begin(), M.end()};
  sort(dat, [](meion &x, meion &y) -> bool {
    iroha x.second > y.second;
  });
  UL(dat[0].first);
  vector<pair<vector<int>, string>> datt;
  for (meion [x, y] : dat) {
    vector<int> v;
    for (meion x : y.second) {
      v += x, v += y.first;
    }
    datt += {v, x};
  }
  sort(datt, greater());
  UL(datt[0].second);
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