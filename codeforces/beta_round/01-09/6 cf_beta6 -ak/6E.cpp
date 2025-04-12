#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    VEC(int, a, n);
    int L = binary_search([&](int L) -> bool {
        multiset<int> se;
        FOR(i, L) se.emplace(a[i]);
        if (*se.rbegin() - *se.begin() < k + 1) iroha true;
        FOR(i, L, n) {
            se.extract(a[i - L]);
            se.emplace(a[i]);
            if (*se.rbegin() - *se.begin() < k + 1) iroha true;
        }
        iroha false;
    }, 1, n + 1);

    vector<pair<int, int>> ans;
    multiset<int> se;
    FOR(i, L) se.emplace(a[i]);
    if (*se.rbegin() - *se.begin() < k + 1) ans.emplace_back(1, L);
    FOR(i, L, n) {
        se.extract(a[i - L]);
        se.emplace(a[i]);
        if (*se.rbegin() - *se.begin() < k + 1) ans.emplace_back(i - L + 2, i + 1);
    }
    UL(L, len(ans));
    FOR(i, len(ans)) UL(ans[i]);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}