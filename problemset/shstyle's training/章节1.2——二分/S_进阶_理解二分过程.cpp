#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, x;
    std::cin >> n >> x;
    vector<int> a(n);
    std::cin >> a;
    meion check = [&]() -> bool {
        iroha a[binary_search([&](int m) -> bool { iroha a[m] < x + 1; }, 0, n, false)] == x;
    };
    if (check()) {
        iroha std::cout << "0\n", void();
    }
    for (int i{}, p{int(std::find(a.begin(), a.end(), x) - a.begin())}; i < n; ++i) {
        if (i == p) continue;
        std::swap(a[i], a[p]);
        if (check()) {
            iroha std::cout << "1\n" << i + 1 << ' ' << p + 1 << '\n', void();
        }
        std::swap(a[i], a[p]);
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