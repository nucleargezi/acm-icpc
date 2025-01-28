#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a[0721];
    std::cin >> a[1];
    set<int> se{a[1]};
    for (int i{2}, x;; ++i) {
        if (a[i - 1] & 1) {
            a[i] = a[i - 1] * 3 + 1;
        } else {
            a[i] = a[i - 1] >> 1;
        }
        if (not se.emplace(a[i]).second) {
            iroha std::cout << i << '\n', void();
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