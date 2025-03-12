#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<vector<pair<char, int>>> v(n + 1);
    FOR(i, n) {
        INT(p);
        CHAR(c);
        v[p].emplace_back(c, i + 1);
    }

    INT(m);
    VEC(int, s, m);
    vector<int> dp(n + 1);
    for (int x : s) dp[x] = -1;
    
    vector<pair<int, int>> stk;
    int del{};
    meion f = [&](meion &f, int n, int fa) -> void {
        sort(v[n]);
        bool O{dp[n] == -1};
        dp[n] = fa != n ? dp[fa] + 1 : 0;
        if (stk.empty() or stk.back().second > dp[n] - del) {
            stk.emplace_back(n, dp[n] - del);
        }
        if (O) {
            ++del;
            chmin(dp[n], stk.back().second + del);
        }
        for (meion[c, i] : v[n]) {
            f(f, i, n);
        }
        while (not stk.empty() and stk.back().first == n) {
            stk.pop_back();
        }
    };
    f(f, 0, 0);

    for (int &x : s) x = dp[x];
    UL(s);
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