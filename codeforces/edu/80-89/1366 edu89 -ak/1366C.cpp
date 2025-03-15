#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VVEC(int, a, n, m);

    vector<vector<int>> sets(ceil(n + m - 1, 2));
    FOR(i, n) FOR(k, m) {
        sets[MIN(i + k, n + m - 2 - i - k)].emplace_back(a[i][k]);
    }
    if (n + m & 1 ^ 1) sets.pop_back();

    int ans{};
    for (meion &v : sets) {
        map<int, int> m;
        for (int x : v) ++m[x];
        int max{-inf<int>};
        for (meion [x, y] : m) chmax(max, y);
        ans += len(v) - max;
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