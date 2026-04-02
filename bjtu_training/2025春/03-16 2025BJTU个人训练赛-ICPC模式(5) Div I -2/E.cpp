#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    
    map<pair<ll, ll>, pair<ll, ll>> M;
    int ans{};
    FOR(i, n) {
        ll x{1}, y{1};
        for (meion [e, p] : factor(a[i])) {
            p %= 3;
            if (p == 2) x *= e;
            if (p == 1) y *= e;
        }
        if (x == 1 and y == 1) {
            ans = 1;
            continue;
        }
        if (x < y) ++M[{x, y}].first;
        else ++M[{y, x}].second;
    }
    
    for (meion [x, y] : M) {
        ans += MAX(y.first, y.second);
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