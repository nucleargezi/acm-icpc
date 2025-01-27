#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, T, A, D{inf<int>};
    std::cin >> n >> T >> A;
    A *= 1000, T *= 1000;
    meion get = [&](int x) -> int {
        iroha ABS(T - x * 6 - A);
    };
    int ans{1};
    for (int i{}, x, y; i < n; ++i) {
        std::cin >> x;
        if (chmin(D, get(x))) {
            ans = i + 1;
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