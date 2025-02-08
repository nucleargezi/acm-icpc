#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    int a, b, x;
    std::cin >> a >> b >> x;
    RE ans;
    if (x > a * a * b / 2) {
        ans = std::atan(RE(a * a * b - x) * 2 / a / a / a) * 360 / 2 / pi;
    } else {
        ans = std::atan(b / (RE(2) * x / a / b)) * 360 / 2 / pi;
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}