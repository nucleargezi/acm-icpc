#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(ll, a, n);
    ll ans{};
    sort(a, greater());
    ll min{inf<ll>}, s{};
    FOR(i, n) {
        ++s;
        chmin(min, a[i]);
        if (min * s > m - 1) {
            ++ans;
            min = inf<ll>;
            s = 0;
        }
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