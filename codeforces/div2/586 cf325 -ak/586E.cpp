#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(x, y);
    vector<pair<ll, char>> go;
    while (MIN(x, y) > 1) {
        if (x > y) {
            go.emplace_back(x / y, 'A');
            x %= y;
            if (not x) iroha Impossible();
        } else {
            go.emplace_back(y / x, 'B');
            y %= x;
            if (not y) iroha Impossible();
        }
    }
    if (x == 1 and y == 1) iroha Impossible();
    if (x > 1) go.emplace_back(x - 1, 'A');
    else go.emplace_back(y - 1, 'B');
    string ans;
    for (meion [x, y] : go) {
        ans += std::to_string(x) + y;
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}