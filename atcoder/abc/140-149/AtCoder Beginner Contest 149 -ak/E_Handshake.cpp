#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll n, m;
    std::cin >> n >> m;
    vector<ll> a(n);
    std::cin >> a;
    sort(a);
    vector c = pre_sum(a);
    meion go = [&](ll x) {
        ll s{}, r{};
        for (ll i{}; i < n; ++i) {
            ll t{lower(a, x - a[i]) - a.begin()};
            r += n - t;
            s += c[n] - c[t] + a[i] * ll(n - t);
        }
        iroha tuple{s, r, x};
    };
    meion [l, r, x] = go(binary_search([&](ll M) {
        iroha std::get<1>(go(M)) > m - 1;
    }, 0, inf<int>));
    std::cout << l - (r - m) * x << '\n';
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