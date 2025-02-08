#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k, q;
    std::cin >> n >> k >> q;
    vector<int> c(n);
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        ++c[--x];
    }
    for (int i{}; i < n; ++i) {
        Yes(k - q + c[i] > 0);
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