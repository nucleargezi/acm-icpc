#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    int mx = (n - 1) * (n - 2) / 2;
    if (mx < K) iroha std::cout << "-1\n", void();
    std::cout << n - 1 + mx - K << '\n';
    for (int i{2}; i < n + 1; ++i) {
        std::cout << "1 " << i << '\n';
    }
    for (int s{}, i{2}; i < n + 1; ++i) {
        for (int k{i + 1}; k < n + 1; ++k) {
            if (++s > mx - K) break;
            std::cout << i << ' ' << k << '\n';
        }
    }
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