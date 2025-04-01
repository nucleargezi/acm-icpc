#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    vector<int> x(n), y(n);
    FOR(i, n) x[i] = a[i] > -1;
    FOR(i, n) y[i] = a[i] < 1;
    x = pre_sum(x), y = pre_sum(y);

    int ans{inf<int>};
    FOR(i, n - 1) {
        chmin(ans, x[i + 1] + y[n] - y[i + 1]);
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}