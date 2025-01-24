#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    set<int> s;
    int l, r, k;
    std::cin >> l >> r >> k;
    for (int i{l}; i < r + 1 and i < l + k; ++i) {
        s.emplace(i);
    }
    for (int i{r}; i > r - k and i > l - 1; --i) {
        s.emplace(i);
    }
    for (int x : s) {
        std::cout << x << '\n';
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