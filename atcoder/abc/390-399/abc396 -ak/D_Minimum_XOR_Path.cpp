#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  ll dis[n][n];
  memset(dis, -1, sizeof dis);
  FOR(m) {
    LL(x, y, w);
    --x, --y;
    dis[x][y] = dis[y][x] = w;
  }

  ll ans{inf<ll>};
  FOR(i, 1 << n - 2) {
    vector<ll> I;
    FOR(k, n - 2) {
      if (i >> k & 1) {
        I += k + 1;
      }
    }
    do {
      vector<ll> t{0};
      t += I;
      t += n - 1;
      ll res{}, f{1};
      FOR(i, 1, len(t)) {
        f &= dis[t[i - 1]][t[i]] != -1;
        res ^= dis[t[i - 1]][t[i]];
      }
      if (f) chmin(ans, res);
    } while (std::next_permutation(I.begin(), I.end()));
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