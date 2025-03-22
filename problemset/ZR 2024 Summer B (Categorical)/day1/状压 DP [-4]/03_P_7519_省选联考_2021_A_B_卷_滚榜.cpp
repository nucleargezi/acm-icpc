#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);

    vector d(n, vector<int>(n));
    FOR(i, n) FOR(k, n) chmax(d[i][k], a[i] - a[k] + (i < k));
    vector<int> s(n);
    FOR(i, n) FOR(k, n) chmax(s[k], d[i][k]);
    
    const int N{1 << n};
    vector dp(N, vector(n, array<int, 501>{}));
    FOR(i, n) if (n * s[i] < m + 1) dp[1 << i][i][n * s[i]] = 1;
    
    FOR(msk, N) FOR(i, n) if (msk >> i & 1) {
        int nx{msk ^ (1 << i)}, c{n - popcount(nx)};
        FOR(k, n) if (i != k and (msk >> k & 1)) {
            FOR(j, d[k][i] * c, m + 1) {
                dp[msk][i][j] += dp[nx][k][j - d[k][i] * c];
            }
        }
    }

    ll ans{};
    FOR(i, n) FOR(k, m) ans += dp[N - 1][i][k + 1];
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