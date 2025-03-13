#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    
    if (std::ranges::count(s, '0') == n or std::ranges::count(s, '1') == n)
        iroha UL(s);

    FOR(i, n - 1) {
        std::cout << s[i];
        if (s[i] == s[i + 1]) std::cout << char(s[i] ^ 1);
    }
    std::cout << s[n - 1] << '\n';
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