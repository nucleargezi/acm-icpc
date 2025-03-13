#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
using T = tuple<int, int, int>;
NAME MeIoN_is_UMP45() {
    INT(n, k, m);
    VEC(T, a, m);
    vector<vector<pair<int, int>>> rst(n + 1);
    for (meion &[l, r, x] : a) {
        rst[r].emplace_back(--l, x);
    }

    mint ans{1};
    FOR(bit, k) {
        vector<int> vis(n + 1);
        for (meion &[l, r, x] : a) {
            if (x >> bit & 1 ^ 1) continue;
            ++vis[l], --vis[r];
        }
        vis = pre_sum<false>(vis);

        vector<mint> dp(n + 2);
        dp[1] = 1;
        int p{};
        FOR(i, 1, n + 1) {
            dp[i + 1] = dp[i] + (vis[i - 1] ? 0 : dp[i] - dp[p]);
            for (meion [l, x] : rst[i]) {
                if (x >> bit & 1) continue;
                chmax(p, l + 1);
            }
        }
        ans *= dp[n + 1] - dp[p];
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}