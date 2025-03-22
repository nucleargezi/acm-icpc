#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
using RE = f128;
NAME MeIoN_is_UMP45() {
    LL(n);
    VEC(P, ps, n);

    INT(q);
    FOR(q) {
        LL(x, y);
        vector<RE> a(n);
        FOR(i, n) {
            meion [X, Y] = ps[i] - P(x, y);
            a[i] = std::atan2(Y, X);
        }
        sort(a);
        FOR(i, n) a.emplace_back(a[i] + pi + pi);
        ll ans{n * (n - 1) * (n - 2) / 6};
        FOR(i, n) {
            ll x{lower(a, a[i] + pi) - a.begin() - i};
            ans -= (x - 1) * (x - 2) / 2;
        }
        UL(ans);
    }
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