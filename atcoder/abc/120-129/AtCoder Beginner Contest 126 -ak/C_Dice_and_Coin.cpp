#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    using RE = ld;
    RE ans{};
    for (int i{1}; i < MIN(n + 1, k); ++i) {
        int c{}, x{i};
        while (x < k) ++c, x <<= 1;
        ans += std::pow<RE, int>(0.5L, c);
    }
    std::cout << (n > k - 1 ? RE(n - k + 1) / n : 0.L) + ans / n
              << '\n';
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