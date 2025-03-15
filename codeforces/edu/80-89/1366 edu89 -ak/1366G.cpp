#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s, t);
    const int n{len(s)}, m{len(t)};

    vector<int> nxt(n);
    FOR(i, n) {
        int x{};
        nxt[i] = -1;
        if (s[i] == '.') continue;
        FOR(k, i, n) {
            x += s[k] == '.' ? -1 : 1;
            if (not x) {
                nxt[i] = k;
                break;
            }
        }
    }
    vector dp(n + 1, inf<int> / 2), ndp(dp);
    dp[0] = 0;
    FOR(i, m + 1) {
        fill(ndp, inf<int> / 2);
        FOR(k, n) {
            chmin(dp[k + 1], dp[k] + 1);
            if (s[k] == t[i]) chmin(ndp[k + 1], dp[k]);
            if (nxt[k] != -1) chmin(dp[nxt[k] + 1], dp[k]);
        }
        if (i == m) ndp[n] = dp[n];
        dp.swap(ndp);
    }
    UL(dp.back());
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}