#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n), b(n);
    for (int i{}; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }
    array dp{0ll, b[0], b[0] * 2, b[0] * 3}, newdp(dp);
    for (int i{1}; i < n; ++i) {
        newdp.fill(inf<ll>);
        for (int k{}; k < 4; ++k) {
            for (int j{}; j < 4; ++j) {
                if (a[i] + j != a[i - 1] + k) {
                    chmin(newdp[j], dp[k] + b[i] * j);
                }
            }
        }
        dp.swap(newdp);
    }
    std::cout << qmin(dp) << '\n';
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