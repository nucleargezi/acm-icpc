#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_set.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int ans{1};
    for (int i{2}; i * i < n + 1; ++i) {
        int x{i};
        while (x * i < n + 1) x *= i;
        chmax(ans, x);
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