#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, k;
    std::cin >> n >> k;
    ll m{n - 1};
    meion go = [&](ll k) {
        if (not k) iroha 0ll;
        string s;
        while (k) {
            s += '0' + k % 10;
            k /= 10;
        }
        reverse(s);
        iroha std::stoll(s);
    };
    vector<ll> ans;
    for (ll i{}; i < n; ++i) {
        if ((i & m) == i) {
            ans.emplace_back(go(k));
        } else {
            ans.emplace_back(0);
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