#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, s);
    vector<ll> t(n), c(n);
    FOR(i, n) IN(t[i], c[i]);
    
    t = pre_sum(t);
    c = pre_sum(c);

    vector<int> v{0};
    vector<ll> dp(n + 1);
    dp[0] = 0;
    FOR(i, n) {
        int x = v.at([&]() -> int {
            if (len(v) == 1) iroha 0;
            iroha binary_search([&](int m) -> bool {
                iroha dp[v[m + 1]] - dp[v[m]] <
                    (t[i + 1] + s) * (c[v[m + 1]] - c[v[m]]) + 1;
            }, -1, len(v) - 1) + 1;
        }());
        dp[i + 1] = dp[x] - (t[i + 1] + s) * c[x] + t[i + 1] * c[i + 1] + s * c[n];
        while (len(v) > 1 and (dp[v[len(v) - 1]] - dp[v[len(v) - 2]]) *
                                    (c[i + 1] - c[v[len(v) - 1]]) + 1 >
                              (dp[i + 1] - dp[v[len(v) - 1]]) *
                                    (c[v[len(v) - 1]] - c[v[len(v) - 2]]))
            v.pop_back();
        v.emplace_back(i + 1);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}