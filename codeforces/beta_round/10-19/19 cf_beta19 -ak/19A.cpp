#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(string, s, n);
  map<string, T3<int>> M;
  FOR(n * (n - 1) / 2) {
    S(t, sc);
    FOR(i, len(t)) if (t[i] == '-') {
      string a = t.substr(0, i), b = t.substr(i + 1);
      // debug(a, b);
      FOR(i, len(sc)) if (sc[i] == ':') {
        int x = std::stoi(sc.substr(0, i)), y = std::stoi(sc.substr(i + 1));
        // debug(x, y);
        FOR(2) {
          meion &[sc, ae, e] = M[a];
          sc += x > y ? 3 : x == y ? 1 : 0;
          ae += x - y;
          e += x;
          std::swap(a, b), std::swap(x, y);
        }
        break;
      }
      break;
    }
  }
  vector<pair<T3<int>, string>> q;
  for (meion [x, y] : M) q += {y, x};
  sort(q, greater());
  vector<string> ans;
  FOR(i, n >> 1) ans += q[i].second;
  sort(ans);
  FOR(i, n >> 1) UL(ans[i]);
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