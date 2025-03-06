#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int l, n, k;
    std::cin >> l >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    a.emplace_back(l - a.back());
    for (int i{n}; --i; ) {
        a[i] -= a[i - 1];
    }
    std::cout << binary_search([&](int m) -> bool {
        ll s{};
        for (int x : a) {
            if (not x) continue;
            s += ceil(x, m) - 1;
        }
        iroha s <= k;
    }, inf<int>, 0) << '\n';
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