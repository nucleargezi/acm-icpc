#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<int> m(n + 2), L(n + 2), R(n + 2);
    FOR(i, 1, n + 1) {
        INT(x);
        m[x] = i;
        L[i] = i - 1;
        R[i] = i + 1;
    }
    ll ans{};
    FOR(i, n) {
        int l{L[m[i + 1]]}, r{R[m[i + 1]]};
        if (l > 0) ans += (i + 1) * (l - L[l]) * (r - m[i + 1]);
        if (r < n + 1) ans += (i + 1) * (R[r] - r) * (m[i + 1] - l);
        L[r] = l, R[l] = r;
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