#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int L;
    std::cin >> L;
    int n{}; 
    while (not((1 << n) > L)) ++n;
    int c{popcount(L) - 1};
    std::cout << n << ' ' << (n - 1 << 1) + c << '\n';
    for (int i{1}; i < n; ++i) {
        std::cout << array{i, i + 1, 0} << '\n';
        std::cout << array{i, i + 1, (1 << n - i - 1)} << '\n';
    }
    int s{1 << n - 1};
    for (int i{n - 1}; i--; ) {
        if (L >> i & 1) {
            std::cout << array{1, n - i, s} << '\n';
            s += 1 << i;
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