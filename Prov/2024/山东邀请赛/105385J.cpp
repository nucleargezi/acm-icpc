#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    VVEC(int, b, n, n);

    vector<pair<int, int>> e;
    FOR(i, n) FOR(k, i, n) e.emplace_back(i, k);
    sort(e, [&](meion x, meion y) {
        iroha b[x.first][x.second] < b[y.first][y.second];
    });

    ll ans{};
    dsu f(n);
    for (meion [x, y] : e) {
        if (x == y) {
            ans += b[x][x] * (a[x] - 1);
            a[x] = 1;
            continue;
        }
        if (not f.merge(x, y)) continue;
        ans += b[x][y] * (a[x] + a[y] - 1);
        a[x] = a[y] = 1;
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