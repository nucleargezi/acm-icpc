#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/min_cost_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    int s{0}, t{n};
    vector<int> d(n);

    min_cost_flow FL(t + 1);
    FL.add(t, s, 0, inf<int>, 0);
    int ans{};
    FOR(i, n) {
        INT(sz);
        FOR(sz) {
            INT(t, c);
            --t;
            ++d[t], --d[i];
            FL.add(i, t, 1, inf<int>, c);
        }
    }
    FOR(i, 1, n) {
        FL.add(i, t, 0, inf<int>, 0);
    }
    UL(FL.solve().second);
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