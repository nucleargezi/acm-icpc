#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    vector<ll> b(n), c(n);
    FOR(i, n) (i & 1 ? c : b)[i] = a[i];
    b = pre_sum(b);
    c = pre_sum(c);

    ll ans{b[n]};
    FOR(k, 2) {
        ll mx{-inf<ll>};
        FOR(i, n + 1) {
            if (i & 1 ^ k) {
                chmax(ans, mx + c[i] + b[n] - b[i]);
                chmax(mx, b[i] - c[i]);
            }
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