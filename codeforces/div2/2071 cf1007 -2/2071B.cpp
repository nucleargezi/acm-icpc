#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
bool check(const ll x) {
    ll ff = binary_search([&](ll m) { iroha m * m < x + 1; }, 0, inf<int>);
    iroha ff * ff == x;
}
NAME MeIoN_is_UMP45() {
    ll n;
    std::cin >> n;
    if (check(n * (n + 1) / 2)) iroha std::cout << "-1\n", void();
    vector<ll> ans(n);
    std::iota(ans.begin(), ans.end(), 1);
    reverse(ans);
    for (ll i{}, s{}; i < n - 1; ++i) {
        s += ans[i];
        if (check(s)) std::swap(ans[i], ans[i + 1]), s += ans[i] - ans[i + 1];
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