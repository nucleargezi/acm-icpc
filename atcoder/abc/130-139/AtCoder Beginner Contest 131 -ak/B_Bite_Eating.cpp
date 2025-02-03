#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, l;
    std::cin >> n >> l;
    int s{n * l + (n - 1) * n / 2};
    pair min{inf<int>, -1};
    for (int i{}; i < n; ++i) {
        chmin(min, pair{ABS(l + i), l + i});
    }
    std::cout << s - min.second << '\n';
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