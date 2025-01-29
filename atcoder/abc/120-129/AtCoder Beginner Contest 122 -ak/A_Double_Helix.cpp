#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    char b;
    std::cin >> b;
    if (b == 'A') {
        std::cout << 'T';
    } else if (b == 'T') {
        std::cout << 'A';
    } else if (b == 'C') {
        std::cout << 'G';
    } else {
        std::cout << 'C';
    }
    std::cout << '\n';
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