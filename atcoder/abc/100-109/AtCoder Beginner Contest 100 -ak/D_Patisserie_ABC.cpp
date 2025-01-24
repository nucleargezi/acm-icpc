#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector dp(8, vector<ll>(n));
    for (int i{}; i < n; ++i) {
        array<ll, 3> a;
        std::cin >> a;
        for (int msk{}; msk < 8; ++msk) {
            for (int bit{}; bit < 3; ++bit) {
                if (msk >> bit & 1) {
                    dp[msk][i] -= a[bit];
                } else {
                    dp[msk][i] += a[bit];
                }
            }
        }
    }
    ll ans{};
    for (meion &v : dp) {
        sort(v, greater());
        v.resize(m);
        chmax(ans, qsum(v, 0ll));
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