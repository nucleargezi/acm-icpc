#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    VEC(int, a, m + 1);
    
    mint C[32][32];
    FOR_R(i, 32) FOR_R(k, i + 1) {
        C[i][k] = C_dense<mint>(i, k);
    }
    
    vector<mint> pow[m + 1];
    FOR(i, m + 1) pow[i] = power_table_1(mint(a[i]), n + 1);
    
    vector dp(32, vector(32, vector<mint>(32)));
    dp[0][0][0] = 1;
    
    FOR(b, m + 21) {
        vector ndp(32, vector(32, vector<mint>(32)));
        FOR(t, n + 1) FOR(go, n + 1) FOR(one, k + 1) {
            if (dp[t][go][one] == 0) continue;
            if (b < m + 1) {
                FOR(cnt, n - t + 1) {
                    int tot{go + cnt};
                    int none = (tot & 1) + one;
                    if (none > k) continue;
                    ndp[t + cnt][tot >> 1][none] += dp[t][go][one] * C[n - t][cnt] * pow[b][cnt];
                }
            } else {
                int tot{go};
                int none{(tot & 1) + one};
                if (none > k) continue;
                ndp[t][tot >> 1][none] += dp[t][go][one];
            }
        }
        dp.swap(ndp);
    }

    mint ans;
    FOR(i, k + 1) ans += dp[n][0][i];
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