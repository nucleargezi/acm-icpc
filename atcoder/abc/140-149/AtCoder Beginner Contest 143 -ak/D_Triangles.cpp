#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    ll ans{};
    for (int i{}; i < n; ++i) {
        for (int k{i + 1}; k < n; ++k) {
            ans += MAX(int(lower(a, a[i] + a[k]) - a.begin()) - k - 1, 0);
        }
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