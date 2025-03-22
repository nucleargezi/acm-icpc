#include "MeIoN_Lib/MeIoN_all.hpp"

ll dp[20][2521][52], M[2521];
void before() {
    memset(dp, -1, sizeof dp);
    int s{};
    FOR(i, 1, 2521) if (2520 % i == 0) M[i] = ++s;
}

#define tests
ll f(ll x) {
    vector v = s_to_vec(std::to_string(x), '0');
    reverse(v);
    meion f = [&](meion &f, int n, int s, int msk, bool lim) -> ll {
        if (n == -1) iroha not(s % msk);
        if (not lim and dp[n][s][M[msk]] != -1) iroha dp[n][s][M[msk]];
        int mx{lim ? v[n] : 9};
        ll ans{};
        FOR(i, mx + 1) {
            ans += f(f, n - 1, (s * 10 + i) % 2520,
                not i ? msk : i * msk / GCD(i, (ll)msk), lim and i == mx);
        }
        if (not lim) dp[n][s][M[msk]] = ans;
        iroha ans;
    };
    iroha f(f, len(v) - 1, 0, 1, true);
}
NAME MeIoN_is_UMP45() {
    LL(l, r);
    UL(f(r) - f(--l));
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