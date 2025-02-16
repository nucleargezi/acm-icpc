#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    vector<ll> b(n), c(n);
    for (int i{}; i < n; ++i) {
        if (a[i] > 0) b[i] = a[i];
        else c[i] = -a[i];
    }
    b = pre_sum(b);
    c = pre_sum(c);
    ll ans{-inf<ll>};
    for (int i{}; i < n + 1; ++i) {
        chmax(ans, b[i] - b[0] + c[n] - c[i]);
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