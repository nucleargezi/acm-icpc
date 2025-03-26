#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    LL(n, m, d);
    VEC(string, s, n);

    vector<mint> dp(m);
    vector<int> c(m);
    FOR(i, m) c[i] = s[0][i] == 'X';
    c = pre_sum(c);
    FOR(i, m) if (s[0][i] == 'X') {
        dp[i] += c[MIN(m, i + 1 + d)] - c[MAX(0ll, i - d)];
    }
    FOR(i, 1, n) {
        vector<mint> c = dp, ndp(m);
        c = pre_sum(c);
        FOR(k, m) if (s[i][k] == 'X') {
            ndp[k] += c[MIN(m, k + d)] - c[MAX(0ll, k - d + 1)];
        }
        dp.swap(ndp);
        c = dp;
        c = pre_sum(c);
        fill(ndp, 0);
        FOR(k, m) if (s[i][k] == 'X') {
            ndp[k] += c[MIN(m, k + d + 1)] - c[MAX(0ll, k - d)];
        }
        dp.swap(ndp);
    }
    mint ans;
    FOR(i, m) ans += dp[i];
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