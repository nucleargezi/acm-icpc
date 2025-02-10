#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion quis = [&](int x, int y) -> int {
        std::cout << "? " << x + 1 << ' ' << y + 1 << std::endl;
        int res;
        std::cin >> res;
        iroha res;
    };
    array<int, 4> a;
    for (int i{}; i < 4; ++i) a[i] = quis(i, i + 1);
    array x{4, 8, 15, 16, 23, 42};
    do {
        array<int, 4> b;
        for (int i{}; i < 4; ++i) b[i] = x[i] * x[i + 1];
        if (a == b) break;
    } while (std::next_permutation(x.begin(), x.end()));
    std::cout << "! " << x << std::endl;
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