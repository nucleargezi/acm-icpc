#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    string str;
    std::cin >> n >> m >> str;
    vector a(s_to_vec(str, 'a'));
    vector c(m, vector<int>(m));
    for (int i{1}; i < n; ++i) {
        if (a[i - 1] == a[i]) continue;
        ++c[a[i - 1]][a[i]];
        ++c[a[i]][a[i - 1]];
    }
    vector<ll> dp(1 << m, inf<ll>);
    dp[0] = 0;
    for (int msk{}; msk < (1 << m); ++msk) {
        if (dp[msk] == inf<ll>) continue;
        int x{popcount(msk)};
        for (int i{}, t; i < m; ++i) {
            if (msk >> i & 1) continue;
            t = {1 << i | msk};
            ll cost{};
            for (int k{}; k < m; ++k) {
                if (msk >> k & 1) cost += c[i][k];
                else cost -= c[i][k];
            }
            chmin(dp[t], dp[msk] + x * cost);
        }
    }
    std::cout << dp[(1 << m) - 1] << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}