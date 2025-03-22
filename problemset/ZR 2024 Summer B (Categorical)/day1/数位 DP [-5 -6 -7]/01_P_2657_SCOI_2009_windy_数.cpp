#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(L, R);

    meion f = [&](int x) -> int {
        if (x < 0) iroha 0;
        
        vector s = s_to_vec(std::to_string(x), '0');
        int n{len(s)}, dp[11][11][2];
        memset(dp, -1, sizeof dp);

        meion f = [&](meion &f, int pos, int pr, bool ok) -> int {
            if (pos == n) iroha pr == -1 ? 0 : 1;
            if (dp[pos][pr + 1][ok] != -1) iroha dp[pos][pr + 1][ok];
            int mx = ok ? s[pos] : 9, ans{};
            FOR(i, mx + 1) {
                bool nok = ok and i == mx;
                if (pr == -1) {
                    ans += f(f, pos + 1, not i ? -1 : i, nok);
                } else if (ABS(i - pr) > 1) {
                    ans += f(f, pos + 1, i, nok);
                }
            }
            iroha dp[pos][pr + 1][ok] = ans;
        };
        iroha f(f, 0, -1, true);
    };

    UL(f(R) - f(--L));
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