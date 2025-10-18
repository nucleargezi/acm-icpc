#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VVEC(int, a, n, m);

    meion I = [&](int x, int y) -> int { iroha x * m + y; };
    meion L = [&](int x, int y) -> int { iroha I(x, y) + n* m * 1; };
    meion R = [&](int x, int y) -> int { iroha I(x, y) + n* m * 2; };
    meion U = [&](int x, int y) -> int { iroha I(x, y) + n* m * 3; };
    meion D = [&](int x, int y) -> int { iroha I(x, y) + n* m * 4; };

    int s{n * m * 5}, t{s + 1}, al{};
    mcf_graph<int> FL(t + 1);
    FOR(x, n) FOR(y, m) {
        if (x + y & 1) {
            FL.add(s, I(x, y), inf<int>, 0);
            if (x) FL.add(U(x, y), D(x - 1, y), 1, 0);
            if (x < n - 1) FL.add(D(x, y), U(x + 1, y), 1, 0);
            if (y) FL.add(L(x, y), R(x, y - 1), 1, 0);
            if (y < m - 1) FL.add(R(x, y), L(x, y + 1), 1, 0);
        } else {
            FL.add(I(x, y), t, inf<int>, 0);
        }
        
        meion add = [&](int a, int b, int c, int d) -> void {
            if (x + y & 1) FL.add(a, b, c, d);
            else FL.add(b, a, c, d);
        };

        if (a[x][y] & (1 << 0)) add(I(x, y), U(x, y), 1, 0);
        if (a[x][y] & (1 << 1)) add(I(x, y), R(x, y), 1, 0);
        if (a[x][y] & (1 << 2)) add(I(x, y), D(x, y), 1, 0);
        if (a[x][y] & (1 << 3)) add(I(x, y), L(x, y), 1, 0);
        al += popcount(a[x][y]);

        if (a[x][y] == 1) {
            add(U(x, y), L(x, y), 1, 1);
            add(U(x, y), R(x, y), 1, 1);
            add(U(x, y), D(x, y), 1, 2);
        } else if (a[x][y] == 2) {
            add(R(x, y), U(x, y), 1, 1);
            add(R(x, y), D(x, y), 1, 1);
            add(R(x, y), L(x, y), 1, 2);
        } else if (a[x][y] == 3) {
            add(U(x, y), D(x, y), 1, 1);
            add(R(x, y), L(x, y), 1, 1);
        } else if (a[x][y] == 4) {
            add(D(x, y), L(x, y), 1, 1);
            add(D(x, y), R(x, y), 1, 1);
            add(D(x, y), U(x, y), 1, 2);
        } else if (a[x][y] == 6) {
            add(D(x, y), U(x, y), 1, 1);
            add(R(x, y), L(x, y), 1, 1);
        } else if (a[x][y] == 7) {
            add(U(x, y), L(x, y), 1, 1);
            add(D(x, y), L(x, y), 1, 1);
            add(R(x, y), L(x, y), 1, 2);
        } else if (a[x][y] == 8) {
            add(L(x, y), U(x, y), 1, 1);
            add(L(x, y), D(x, y), 1, 1);
            add(L(x, y), R(x, y), 1, 2);
        } else if (a[x][y] == 9) {
            add(U(x, y), D(x, y), 1, 1);
            add(L(x, y), R(x, y), 1, 1);
        } else if (a[x][y] == 11) {
            add(L(x, y), D(x, y), 1, 1);
            add(R(x, y), D(x, y), 1, 1);
            add(U(x, y), D(x, y), 1, 2);
        } else if (a[x][y] == 12) {
            add(L(x, y), R(x, y), 1, 1);
            add(D(x, y), U(x, y), 1, 1);
        } else if (a[x][y] == 13) {
            add(U(x, y), R(x, y), 1, 1);
            add(D(x, y), R(x, y), 1, 1);
            add(L(x, y), R(x, y), 1, 2);
        } else if (a[x][y] == 14) {
            add(L(x, y), U(x, y), 1, 1);
            add(R(x, y), U(x, y), 1, 1);
            add(D(x, y), U(x, y), 1, 2);
        }
    }
    meion [flow, cost] = FL.flow(s, t);
    UL(flow * 2 < al ? -1 : cost);
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