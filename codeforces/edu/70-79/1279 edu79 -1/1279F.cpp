#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/fibonacci_search.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k, l;
    string s;
    std::cin >> n >> k >> l >> s;
    vector<int> a(n);
    for (int i{}; i < n; ++i) {
        a[i] = (s[i] > 'A' - 1 and s[i] < 'Z' + 1);
    }
    if (1ll * k * l > n - 1) iroha std::cout << "0\n", void();
    ll ans{inf<ll>};
    for (int _ : {0, 1}) {
        chmin(ans, fibonacci_search<ll, false>([&](ll m) -> ll {
            vector<ll> dp(n + 1, inf<ll>);
            dp[0] = 0;
            for (int i{1}; i < n + 1; ++i) {
                chmin(dp[i], dp[i - 1] + a[i - 1]);
                if (i > l - 1) chmin(dp[i], dp[i - l] + m);
            }
            iroha dp[n] - m * k;
        }, -2 * n, 2 * n).first);
        for (int &x : a) x ^= 1;
    }
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