#include "MeIoN_Lib/MeIoN_all.hpp"

int a[100];
int s;
void before() {
    for (int i{0}; i < 15; ++i) {
        a[i] = i % 3 == i % 5;
        s += a[i];
    }
}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int ans = n / 15 * s;
    n %= 15;
    for (int i{}; i < n + 1; ++i) {
        ans += a[i];
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