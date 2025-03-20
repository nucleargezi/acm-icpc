#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VVEC(int, a, 3, n);
    
    FOR(i, 3) sort(a[i]);
    vector<ll> c(n);
    FOR(i, n) c[i] = lower(a[0], a[1][i]) - a[0].begin();
    c = pre_sum(c);
    ll ans{};
    FOR(i, n) {
        ans += c[lower(a[1], a[2][i]) - a[1].begin()];
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