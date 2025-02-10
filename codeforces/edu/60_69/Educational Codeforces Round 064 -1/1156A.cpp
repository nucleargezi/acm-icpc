#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int ans{};
    for (int i{1}; i < n; ++i) {
        if (a[i - 1] + a[i] == 5) iroha std::cout << "Infinite\n", void();
        ans += a[i - 1] + a[i];
        ans -= i > 1 and a[i - 2] == 3 and a[i - 1] == 1 and a[i] == 2;
    }
    std::cout << "Finite\n" << ans << '\n';
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