#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  int v[n][n];
  ll s{};
  FOR(i, n) FOR(k, n) IN(v[i][k]), s += v[i][k];
  s >>= 1;
 
  INT(m);
  vector<ll> ans(m);
  FOR(i, m) {
    INT(x, y, w);
    --x, --y;
    if (w < v[x][y]) {
      s += w - v[x][y];
      v[x][y] = v[y][x] = w;
      FOR(i, n) FOR(k, n) FOR(2) {
        std::swap(x, y);
        if (v[i][k] > w + v[i][x] + v[k][y]) {
          s += w + v[i][x] + v[k][y] - v[i][k];
          v[k][i] = v[i][k] = w + v[i][x] + v[k][y];
        }
      }
    }
    ans[i] = s;
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