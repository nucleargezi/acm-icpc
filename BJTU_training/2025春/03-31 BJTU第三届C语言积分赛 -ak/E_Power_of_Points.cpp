#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    meion rk = argsort(a);
    sort(a);
    vector<ll> c = pre_sum(a), ans(n);
    FOR(i, n) {
        ans[rk[i]] = a[i] * i - c[i] + c[n] - c[i] - a[i] * (n - i) + n;
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