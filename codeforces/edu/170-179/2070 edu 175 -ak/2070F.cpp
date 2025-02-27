#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/math/mod/fwt_or.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> s(m), a(n);
    for (int i{}; i < m; ++i) {
        string str;
        std::cin >> str;
        for (char c : str) {
            s[i] |= 1 << c - 'A';
        }
    }
    std::cin >> a;

    int S{qsum(a, 0)};    
    vector<int> SS(1 << n, S), cnt_o(1 << n);
    for (int msk{}; msk < (1 << n); ++msk) {
        for (int i{}; i < n; ++i) {
            cnt_o[msk] += msk >> i & a[i] & 1;
            if (msk >> i & 1) {
                SS[msk] -= a[i];
            }
        }
    }
    vector<ll> ans(S + 1);
    vector dp(n + 1, vector<ll>(1 << n)), dpp(dp);
    for (int i{}; i < m; ++i) {
        ++dp[cnt_o[s[i]]][s[i]];
        ans[SS[s[i]]] -= not cnt_o[s[i]];
    }
    for (int i{}; i < n + 1; ++i) {
        fwt_or(dp[i]);
    }
    for (int msk{}; msk < (1 << n); ++msk) {
        for (int i{}; i < n + 1; ++i) {
            for (int k{}; k < n + 1 - i; ++k) {
                dpp[i + k][msk] += dp[i][msk] * dp[k][msk];
            }
        }
    }
    for (int i{}; i < n + 1; ++i) {
        fwt_ior(dpp[i]);
    }
    for (int i{}; i < (1 << n); i++) {
        ans[SS[i]] += dpp[cnt_o[i]][i];
    }
    for (ll &x : ans) x >>= 1;
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}