#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll r, b, k;
    std::cin >> r >> b >> k;
    if (r > b) std::swap(r, b);
    ll gcd{GCD(r, b)};
    r /= gcd, b /= gcd;
    std::cout << ((k > b or --k * r > b - 2) ? "OBEY\n" : "REBEL\n");
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