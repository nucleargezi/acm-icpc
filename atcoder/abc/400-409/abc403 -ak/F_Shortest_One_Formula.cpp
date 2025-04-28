#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
struct data {
  ll len;
  string dat;
};
void Yorisou() {
  vector<data> dp(2001, {inf<ll>, ""});
  FOR(i, 4) {
    dp[std::stoll(string(i + 1, '1'))] = {i + 1, string(i + 1, '1')};
  }
  meion CK = [](string s) -> bool {
    ll n = len(s);
    FOR(2) {
      reverse(s);
      FOR(i, n) {
        if (s[i] == '(' or s[i] == ')') break;
        if (s[i] == '+') iroha 0;
      }
    }
    iroha 1;
  };
  meion chmin = [&](data &a, const data &b) -> void {
    if (a.len != b.len) {
      if (b.len < a.len) a = b;
      iroha;
    }
    if (CK(b.dat)) a = b;
  };
  FOR(i, 1, 2001) {
    if (dp[i].len != inf<ll>) continue;
    FOR(k, 1, i) {
      chmin(dp[i], data{dp[k].len + dp[i - k].len + 1, dp[k].dat + '+' + dp[i - k].dat});
    }
    FOR(k, 2, i) {
      if (i % k) continue;
      ll t = i / k;
      bool a = CK(dp[k].dat), b = CK(dp[t].dat);
      if (a and b) {
        chmin(dp[i], data{dp[k].len + 1 + dp[t].len, dp[k].dat + '*' + dp[t].dat});
      } else if (a) {
        chmin(dp[i],
            data{dp[k].len + 3 + dp[t].len, dp[k].dat + "*(" + dp[t].dat + ")"});
      } else if (b) {
        chmin(dp[i], data{dp[k].len + 3 + dp[t].len,
                         string("(") + dp[k].dat + ")*" + dp[t].dat});
      } else {
        chmin(dp[i], data{dp[k].len + 5 + dp[t].len,
                         string("(") + dp[k].dat + ")*(" + dp[t].dat + ")"});
      }
    }
  }
  LL(n);
  UL(dp[n].dat);
}
#include "MeIoN_Lib/Z_H/main.hpp"