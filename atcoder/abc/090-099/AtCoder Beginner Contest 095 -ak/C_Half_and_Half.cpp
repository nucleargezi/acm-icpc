#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    int ans;
    if (a + b < 2 * c + 1) {
        ans = a * x + b * y;
    } else {
        if (x < y) {
            ans = MIN(c * 2 * x + (y - x) * b, c * 2 * y);
        } else if (x > y) {
            ans = MIN(c * 2 * y + (x - y) * a, c * 2 * x);
        } else {
            ans = c * 2 * x;
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