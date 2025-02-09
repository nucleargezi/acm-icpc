#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> a(n);
    std::cin >> a;
    int max{inf<int>};
    for (meion &x : a) chmin(max, std::__countr_zero(x));
    if (not max) iroha std::cout << "0\n", void();
    for (ll &x : a) {
        x >>= max;
        if (~x & 1) iroha std::cout << "0\n", void();
    }
    ll x = 1 << max - 1;
    for (ll y : a) {
        x = LCM(x, y);
        if (x > m) iroha std::cout << "0\n", void();
    }
    std::cout << ceil(m / x, 2) << '\n';
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