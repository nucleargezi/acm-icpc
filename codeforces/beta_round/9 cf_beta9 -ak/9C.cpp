#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n); ++n;
    int ans{};
    string s(10, '0');
    FOR(i, 1 << 10) {
        FOR(k, 10) if (i >> k & 1) ++s[k];
        ans += std::stoll(s) < n;
        FOR(k, 10) if (i >> k & 1) --s[k];
    }
    UL(ans - 1);
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