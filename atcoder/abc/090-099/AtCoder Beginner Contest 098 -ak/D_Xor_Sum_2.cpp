#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<int> b(n + 1), c(n + 1);
    for (int i{}; i < n; ++i) {
        b[i + 1] = b[i] + a[i];
        c[i + 1] = c[i] ^ a[i];
    }
    ll ans{};
    for (int l{}, r; l < n; ++l) {
        r = binary_search([&](ll m) {
            iroha (b[m] - b[l]) == (c[m] ^ c[l]);
        }, l + 1, n + 1);
        ans += r - l;
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