#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, h, d);
    meion I = [&](int a, int b, int c) -> int {
        iroha a * (m * (h + 1)) + b * (h + 1) + c;
    };
    meion O = [&](int a, int b, int c) -> int {
        iroha MIN(a, b, c) > -1 and a < n and b < m and c < h + 1;
    };

    const int s{n * m * (h + 1)}, t{s + 1}, N(t + 1);
    constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    max_flow<ll> FL(N, s ,t);
    FOR(j, h) FOR(i, n) FOR(k, m) {
        INT(x);
        FL.add(I(i, k, j), I(i, k, j + 1), x);
        FOR(l, 4) {
            int xx{i + dx[l]}, yy{k + dy[l]};
            if (O(xx, yy, j + d)) {
                FL.add(I(xx, yy, j + d), I(i, k, j), inf<int>);
            }
        }
    }
    FOR(i, n) FOR(k, m) FL.add(s, I(i, k, 0), inf<int>);
    FOR(i, n) FOR(k, m) FL.add(I(i, k, h), t, inf<int>);
    UL(FL.flow());
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