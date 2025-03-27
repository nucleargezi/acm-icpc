#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);
    
    vector<vector<int>> v(m);
    FOR(i, n) v[--a[i]].emplace_back(i);
    int ans{n - 1};
    FOR(i, 1, n) ans -= a[i] == a[i - 1];
    
    UL(ans);
    dsu f(m);
    FOR(m - 1) {
        INT(x, y);
        x = f[x - 1], y = f[y - 1];
        if (len(v[x]) > len(v[y])) std::swap(x, y);
        for (int v : v[x]) {
            ans -= v != 0 and y == f[a[v - 1]];
            ans -= v != n - 1 and y == f[a[v + 1]];
        }
        v[y] += v[x];
        f.merge_b(y, x);
        UL(ans);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}