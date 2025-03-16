#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    
    ll ans{};
    FOR(i, (1 << n - 1)) {
        ll x{};
        string buf;
        buf += s[0];
        FOR(k, n - 1) {
            if (i >> k & 1) {
                x += std::stoll(buf);
                buf = "";
            }
            buf += s[k + 1];
        }
        x += std::stoll(buf);
        ans += x;
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}