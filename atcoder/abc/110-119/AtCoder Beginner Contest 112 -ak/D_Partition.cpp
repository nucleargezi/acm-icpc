#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_set.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int ans{};
    for (int i{1}; i * i < m + 1; ++i) {
        if (m % i) continue;
        if (i > n - 1) chmax(ans, m / i);
        if (m / i > n - 1) chmax(ans, i);
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