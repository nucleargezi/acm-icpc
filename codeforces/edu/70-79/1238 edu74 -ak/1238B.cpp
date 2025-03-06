#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> a(n);
    std::cin >> a;
    unique(a);
    n = len(a);
    int ans{n};
    for (ll i{}; i < n; ++i) {
        int t{n - i - 1};
        a[i] -= (n - i - 1) * m;
        if (a[i] > 0) t += ceil(a[i], m);
        chmin(ans, t);
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