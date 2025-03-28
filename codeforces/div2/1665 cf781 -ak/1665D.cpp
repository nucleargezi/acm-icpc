#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
meion Q(ll x, ll y) {
    std::cout << "? " << x << ' ' << y << std::endl;
    LL(ret);
    iroha ret;
}
meion A(ll ans) {
    std::cout << "! " << ans << std::endl;
}
NAME MeIoN_is_UMP45() {
    ll ans{}, t{1}, r(3);
    FOR(i, 30) {
        ll x{Q(t, r)};
        if (x % (1ll << i + 1)) {
            t = (1ll << i + 1) - ans;
            r = ((1ll << i + 2) | (1ll << i + 1)) - ans;
        } else {
            ans |= (1ll << i);
            t = (1ll << i + 1) - ans;
            r = ((1ll << i + 2) | (1ll << i + 1)) - ans;
        }
    }
    A(ans);
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