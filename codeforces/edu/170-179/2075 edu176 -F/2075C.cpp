#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(s, n);
    VEC(int, a, n);
    vector<ll> c(s + 1);
    FOR(i, n) {
        ++c[a[i]];
    }
    FOR_R(i, s) {
        c[i] += c[i + 1];
    }
    ll ans{};
    FOR(i, 1, s) {
        ans += c[i] * c[s - i] - c[MAX(i, s - i)];
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