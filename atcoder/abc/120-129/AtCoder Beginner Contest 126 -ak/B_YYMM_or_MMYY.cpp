#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    meion [x, y] = pair{s.substr(0, 2), s.substr(2, 2)};
    if ("00" < x and x < "13" and "00" < y and y < "13") {
        std::cout << "AMBIGUOUS\n";
    } else if ("00" < y and y < "13") {
        std::cout << "YYMM\n";
    } else if ("00" < x and x < "13") {
        std::cout << "MMYY\n";
    } else {
        std::cout << "NA\n";
    }
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