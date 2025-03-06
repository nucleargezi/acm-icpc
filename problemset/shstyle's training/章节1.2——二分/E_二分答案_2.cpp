#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int l, n, m;
    std::cin >> l >> n >> m;
    vector<int> a(n);
    std::cin >> a;
    a.emplace_back(l);
    std::cout << binary_search([&](int d) {
        int s{};
        for (int i{}, f{}; i < n + 1; ++i) {
            if (a[i] - f < d) ++s;
            else f = a[i];
        }
        iroha s <= m;
    }, 0, inf<int>) << '\n';
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