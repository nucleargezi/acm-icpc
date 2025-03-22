#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<int> v(n);
    FOR(m) {
        INT(x, y);
        v[y - 1] |= 1 << x - 1;
    }
    
    const int N{1 << n};
    meion pow = power_table_1(mint(2), N);
    vector<mint> dp(N), f(N), g(N);
    vector<int> e(N);
    f[0] = 1;

    FOR(i, 1, N) {
        int s{};
        FOR(k, n) if (i >> k & 1) s += popcount(v[k] & i);
        dp[i] = pow[s];

        FOR_subset(k, i) if (k & lowbit(i) and k != i) {
            f[i] += dp[k] * g[i ^ k];
            g[i] += dp[k] * f[i ^ k];
        }
        FOR_subset(k, i) if (k) {
            int w{i ^ k}, x{std::__countr_zero(w)};
            if (w) e[w] = e[w ^ (1 << x)] + popcount(v[x] & i);
            dp[i] += pow[e[w]] * (f[k] - g[k]);
        }
        g[i] += dp[i];
    }
    UL(dp.back());
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