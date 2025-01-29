#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll a, b, k;
    std::cin >> a >> b >> k, --k;
    vector<ll> v;
    for (ll i{1}; i < 0721; ++i) {
        if (a % i or b % i) continue;
        v.emplace_back(i);
    }
    sort(v, greater());
    std::cout << v[k] << '\n';
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