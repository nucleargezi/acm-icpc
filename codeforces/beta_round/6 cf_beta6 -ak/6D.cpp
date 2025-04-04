#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, a, b);
    VEC(int, v, n);
    int ans{inf<int>};
    vector<int> path, cur;
    meion f = [&](meion &f, int p, int x) -> void {
        if (x > ans - 1) iroha;
        if (p == n - 1) {
            if (v[p] < 0) {
                ans = x;
                path = cur;
            }
            iroha;
        }
        int mx{MAX(v[p] / a, v[p - 1] / b, v[p + 1] / b) + 1};
        FOR(i, mx + 1) {
            if (v[p - 1] < b * i) {
                v[p] -= a * i, v[p + 1] -= b * i;
                FOR(i) cur.emplace_back(p + 1);
                f(f, p + 1, x + i);
                v[p] += a * i, v[p + 1] += b * i;
                cur.resize(len(cur) - i);
            }
        }
    };
    f(f, 1, 0);
    UL(ans);
    UL(path);
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