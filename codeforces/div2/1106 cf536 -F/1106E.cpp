#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    using A = array<int, 4>;
    VEC(A, a, k);
    sort(a, [](meion &x, meion &y) -> bool {
        iroha pair{x[3], x[2]} > pair{y[3], y[2]};
    });
    vector<int> W(n + 1, -1), R(W);
    multiset<int> se{inf<int>};
    FOR(i, 1, n + 1) se.emplace(i);
    for (meion [l, r ,d, w] : a) {
        while (true) {
            int x = *se.lower_bound(l);
            if (x > r) break;
            W[x] = w, R[x] = d + 1;
            se.extract(x);
        }
    }
    ll dp[n + 2][m + 1];
    std::fill(&dp[0][0], &dp[n + 1][m], inf<ll> / 4);
    dp[1][0] = 0;
    FOR(i, 1, n + 1) {
        FOR(k, m) chmin(dp[i + 1][k + 1], dp[i][k]);
        if (R[i] == -1) {
            FOR(k, m + 1) chmin(dp[i + 1][k], dp[i][k]);
        } else {
            FOR(k, m + 1) chmin(dp[R[i]][k], dp[i][k] + W[i]);
        }
    }
    UL(qmin(vector<ll>{dp[n + 1], dp[n + 1] + m + 1}));
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