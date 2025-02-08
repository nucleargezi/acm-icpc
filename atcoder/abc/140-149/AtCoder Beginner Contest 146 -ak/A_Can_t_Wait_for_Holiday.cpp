#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    int ans{};
    if (s == "SUN") ans = 7;
    if (s == "MON") ans = 6;
    if (s == "TUE") ans = 5;
    if (s == "WED") ans = 4;
    if (s == "THU") ans = 3;
    if (s == "FRI") ans = 2;
    if (s == "SAT") ans = 1;
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