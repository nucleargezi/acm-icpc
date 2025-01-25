#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, g;
    std::cin >> n >> g;
    vector<pair<int, int>> pc(n);
    std::cin >> pc;
    int ans{inf<int>};
    for (int msk{}; msk < (1 << n); ++msk) {
        int s{}, ss{};
        for (int i{}; i < n; ++i) {
            if (msk >> i & 1) {
                s += (i + 1) * 100 * pc[i].first + pc[i].second;
                ss += pc[i].first;
            }
        }
        if (s < g) {
            for (int i{n}; i-- and s < g; ) {
                if (msk >> i & 1) continue;
                int d = MIN(ceil(g - s, (i + 1) * 100), pc[i].first);
                s += (i + 1) * 100 * d;
                ss += d;
            }
        }
        if (s > g - 1) chmin(ans, ss);
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