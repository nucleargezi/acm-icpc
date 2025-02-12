#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, K;
    std::cin >> n >> m >> K;
    vector<ll> a(n);
    std::cin >> a;
    array<ll, 10> c;
    c.fill(-inf<ll> / 16);
    ll ans{};
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) c[k] += a[i];
        c[i % m] = MAX(c[i % m], a[i]) - K;
        chmax(ans, qmax(c));
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