#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<array<int, 2>> ts(n);
    std::cin >> ts;
    sort(ts, [](meion x, meion y) { iroha x[1] < y[1]; });
    for (int s{}; meion [cost, limit] : ts) {
        s += cost;
        if (s > limit) iroha No();
    }
    Yes();
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