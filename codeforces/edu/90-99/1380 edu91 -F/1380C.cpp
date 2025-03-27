#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, x);
    VEC(ll, a, n);
    sort(a, greater());
    
    ll min{inf<ll>}, c{};
    int ans{};
    FOR(i, n) {
        chmin(min, a[i]);
        ++c;
        if (min * c > x - 1) {
            ++ans;
            min = inf<ll>;
            c = 0;
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