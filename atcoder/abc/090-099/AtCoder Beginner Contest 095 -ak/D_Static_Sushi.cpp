#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    ll c;
    std::cin >> n >> c;
    vector<pair<ll, ll>> a(n);
    std::cin >> a;
    ll ans{};
    meion go = [&]() -> void {
        sort(a);
        ll s{}, max{};
        vector<ll> ss(n + 1);
        for (ll pr{}, i{}; meion [x, v] : a) {
            s += v - (x - pr);
            pr = x;
            chmax(max, s);
            ss[++i] = max;
        }
        chmax(ans, ss[n]);
        s = 0;
        for (int i{n}; meion [x, v] : std::views::reverse(a)) {
            s += v;
            chmax(ans, ss[--i] - (c - x) * 2 + s);
        }
    };
    go();
    for (meion &[x, v] : a) {
        x = c - x;
    }
    go();
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