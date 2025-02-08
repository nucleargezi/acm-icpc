#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, x, d;
    std::cin >> n >> x >> d;
    if (not d) iroha std::cout << (x ? n + 1 : 1) << '\n', void();
    int gcd = GCD(x, d);
    x /= gcd, d /= gcd;
    if (d < 0) d = -d, x = -x;
    ll ans = 0;
    meion get = [&](int a, int b) -> ll {
        iroha 1ll * (a + a + b - 1) * b >> 1;
    };
    for (int i = 0; i < d; ++i) {
        set<pair<ll, ll>> s;
        for (int k = i; k < n + 1; k += d) {
            s.emplace(1ll * k / d * x + get(0, k),
                      1ll * k / d * x + get(n - k, k) + 1);
        }
        ll r = -inf<ll>;
        for (meion x : s) {
            ans += MAX(0ll, x.second - MAX(r, x.first));
            chmax(r, x.second);
        }
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