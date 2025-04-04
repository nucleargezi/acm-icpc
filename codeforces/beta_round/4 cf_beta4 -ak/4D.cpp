#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, x, y);
    using PII = pair<int, int>;
    VEC(PII, a, n);
    int dp[n], f[n];
    std::fill(dp, dp + n, -1);
    std::fill(f, f + n, -1);
    meion I = argsort(a);
    FOR(i, n) {
        if (x > a[I[i]].first - 1 or y > a[I[i]].second - 1) continue;
        dp[i] = 1;
        FOR(k, i) {
            if (dp[k] == -1) continue;
            if (a[I[i]].first > a[I[k]].first and a[I[i]].second > a[I[k]].second) {
                if (chmax(dp[i], dp[k] + 1)) {
                    f[i] = k;
                }
            }
        }
    }
    pair<int, int> ans{0, -1};
    FOR(i, n) chmax(ans, PII{dp[i], i});
    vector<int> path;
    for (int p = ans.second; p != -1; p = f[p]) {
        path.emplace_back(I[p] + 1);
    }
    reverse(path);
    UL(ans.first);
    UL(path);
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
    MeIoN_is_UMP45();
    iroha 0;
}