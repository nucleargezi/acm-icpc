#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, c;
    std::cin >> n >> m >> c;
    vector<int> b(m);
    std::cin >> b;
    int ans{};
    for (int i{}; i < n; ++i) {
        vector<int> a(m);
        std::cin >> a;
        ll s{c};
        for (int i{}; i < m; ++i) {
            s += a[i] * b[i];
        }
        ans += s > 0;
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