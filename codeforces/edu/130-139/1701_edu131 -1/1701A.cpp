#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    array<array<int, 2>, 2> a;
    std::cin >> a;
    int ans;
    if (a[0][0] and a[1][1] and a[1][0] and a[0][1]) {
        ans = 2;
    } else if (a[0][0] or a[1][1] or a[1][0] or a[0][1]) {
        ans = 1;
    } else {
        ans = 0;
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