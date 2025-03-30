#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    S(s);
    ll x{}, y{};
    FOR(i, len(s)) {
        (s[i] == '0' ? x : y) += 1;
    }
    bool f{};
    FOR(i, len(s) - 1) {
        f |= s[i] != s[i + 1];
    }
    YES(f or x > y);
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