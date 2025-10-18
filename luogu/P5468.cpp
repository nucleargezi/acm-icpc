#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
uint dp[1'000'01][1001];
NAME MeIoN_is_UMP45() {
    INT(n, m, A, B, C);
    vector<tuple<int, int, int, int>> a(m);
    int T{};
    for (meion &[p, x, y, q] : a) {
        IN(x, y, p, q);
        chmax(T, q);
    }

    meion f = [&](int x) -> int { 
        iroha x * x * A + x * B + C; };

    memset(dp, -1, sizeof dp);
    dp[1][0] = 0;
    for (sort(a); meion [p, x, y, q] : a) {
        FOR(k, p + 1) {
            if (dp[x][k] == inf<uint>) continue;
            chmin(dp[y][q], dp[x][k] + f(p - k));
        }
    }
    uint ans = inf<uint>;
    FOR(i, T + 1) chmin(ans, dp[n][i] + i);
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