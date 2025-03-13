#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using P = pair<int, int>;
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    VEC(P, s, k);
    VEC(P, t, k);
    string ans;
    FOR(i, n - 1) ans += 'U';
    FOR(i, m - 1) ans += 'L';
    FOR(i, n) {
        FOR(m - 1) ans += "RL"[i & 1];
        ans += 'D';
    }
    UL(len(ans));
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