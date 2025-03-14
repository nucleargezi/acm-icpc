#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    S(s);
    
    int x{}, y{};
    FOR(i, 1, n) x += s[i] == s[i - 1];
    FOR(i, 1, n) y += s[i] != s[i - 1];

    vector<int> a;
    while (y) {
        a.emplace_back(MIN(y, 2));
        y -= MIN(y, 2);
    }
    sort(a, greater());
    a.resize(k, 0);
    UL(x + qsum(a, 0));
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}