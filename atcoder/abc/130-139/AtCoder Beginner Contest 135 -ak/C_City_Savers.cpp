#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n + 1), b(n);
    std::cin >> a >> b;
    ll ans{};
    for (int i{}; i < n; ++i) {
        int d{MIN(a[i], b[i])};
        ans += d;
        b[i] -= d;
        d = MIN(a[i + 1], b[i]);
        ans += d;
        a[i + 1] -= d;
    }
    std::cout << ans << '\n';
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