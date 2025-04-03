#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VVEC(int, a, 2, n - 1);
    FOR(i, 2) a[i] = pre_sum(a[i]);
    VEC(int, b, n);
    int ans{inf<int>};
    FOR(i, n) FOR(k, i + 1, n) {
        chmin(ans, b[i] + b[k] + a[0][i] + a[0][k] + a[1][n - 1] * 2 - a[1][i] - a[1][k]);
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