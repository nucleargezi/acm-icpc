#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    map<pair<ull, ull>, ll> m;
    for (int i{}; i < n; ++i) {
        string s;
        std::cin >> s;
        sort(s);
        HASH h(s);
        ++m[h.get(0, s.length())];
    }
    ll ans{};
    for (meion [x, y] : m) {
        ans += (y - 1) * y >> 1;
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