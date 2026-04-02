#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    
    ll ans{};
    FOR(i, n - 1) {
        ans += a[i] >> 1;
        a[i] &= 1;
        if (a[i + 1] and a[i]) ++ans, --a[i + 1];
    }
    UL(ans + a[--n] / 2);
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