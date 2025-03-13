#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    using P = pair<ll, ll>;
    VEC(P, a, n);
    
    vector<ll> ls(n);
    FOR(i, n) {
        int k = (i - 1 + n) % n;
        ls[i] = MAX(0ll, a[i].first - a[k].second);
    }
    ls = pre_sum(ls);

    ll ans{inf<ll>};
    FOR(i, n) {
        chmin(ans, a[i].first + ls[n] - ls[i + 1] + ls[i]);
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