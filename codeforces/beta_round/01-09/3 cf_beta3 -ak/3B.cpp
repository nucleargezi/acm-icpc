#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, v);
    vector<pair<int, int>> one, two;
    FOR(i, n) {
        INT(w, v);
        (w == 1 ? one : two).emplace_back(v, i + 1);
    }
    sort(one, greater());
    sort(two, greater());
    vector<int> L, R;
    for (meion [x, y] : one) L.emplace_back(x);
    for (meion [x, y] : two) R.emplace_back(x);
    L = pre_sum(L);
    R = pre_sum(R);
    int ans{-inf<int>};
    FOR(i, len(L)) {
        if (i > v) break;
        chmax(ans, L[i] + R[MIN(len(R) - 1ll, v - i >> 1)]);
    }
    UL(ans);
    FOR(i, len(L)) {
        if (ans == L[i] + R[MIN(len(R) - 1ll, v - i >> 1)]) {
            FOR(k, i) UL(one[k].second);
            FOR(k, MIN(len(R) - 1ll, v - i >> 1)) UL(two[k].second);
            iroha;
        }
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}