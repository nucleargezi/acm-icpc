#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    Wavelet_Matrix g(a);
    
    INT(q);
    FOR(q) {
        INT(l, r);
        --l;
        int n{MIN(32, r - l)};
        vector<int> a(n);
        FOR(i, n) a[i] = g.kth(l, r, i);
        ll ans{inf<ll>};
        FOR(i, n) FOR(k, i) chmin(ans, a[i] | a[k]);
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