#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<RE> a(n);
    std::cin >> a;
    sort(a);
    RE ans{};
    for (RE i{}, pr{a[0]}; i < n; ++i) {
        ans = pr = (a[i] + pr) / 2;
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