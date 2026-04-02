#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    Yes();
    vector ans(n, vector<int>(n));
    int t{};
    FOR(i, 2) FOR(k, 2) ans[i][k] = ++t;
    FOR(i, 2, n) {
        ++t;
        FOR(k, i + 1) {
            ans[i][k] = t;
        }
        ++t;
        FOR(k, i) {
            ans[k][i] = t;
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