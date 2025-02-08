#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<ll> a(n);
    std::cin >> a;
    vector v(a);
    v.emplace_back(0);
    unique(v);
    for (ll &x : a) x = lower(v, x) - v.begin();
    int m = int(v.size());
    vector dp(1, vector<ll>(m, inf<ll>));
    dp[0][0] = 0;
    for (int i{}; i < n; ++i) {
        vector cp(i + 2, vector<ll>(m, inf<ll>));
        std::swap(cp, dp);
        for (int k{}; k < i + 1; ++k) {
            for (int j{}; j < m; ++j) {
                ll s{cp[k][j]};
                if (s == inf<ll>) continue;
                chmin(dp[k][a[i]], s + MAX(v[a[i]] - v[j], 0ll));
                chmin(dp[k + 1][j], s);
            }
        }
    }
    ll ans{inf<ll>};
    for (int i{}; i < k + 1; ++i) {
        for (int k{}; k < m; ++k) {
            chmin(ans,dp[i][k]);
        }
    }
    std::cout << ans << '\n';
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