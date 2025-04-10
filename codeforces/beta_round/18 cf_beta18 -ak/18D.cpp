#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

// #define tests
using L = BigInteger;
void Yorisou() {
  INT(n);
  map<int, int> M;
  vector<tuple<int, int, L>> T;
  FOR(i, n) {
    S(op);
    INT(v);
    if (op[0] == 'w') {
      M[v] = i;
    } else if (M.contains(v)) {
      L s = 1;
      FOR(v) s *= 2;
      T.emplace_back(-M[v], i, s);
      M.extract(v);
    }
  }
  sort(T);
  vector<L> dp(n + 1);
  FOR(i, n) {
    while (not T.empty() and -std::get<0>(T.back()) == i) {
      meion [l, r, w] = T.back();
      T.pop_back();
      chmax(dp[r], dp[i] + w);
    }
    chmax(dp[i + 1], dp[i]);
  }
  UL(dp[n]);
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