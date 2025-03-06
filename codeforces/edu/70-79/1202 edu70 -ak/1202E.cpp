#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/acam.hpp"

void before() {}

// #define tests

NAME MeIoN_is_UMP45() {
    string t, r_t;
    std::cin >> t;
    int n;
    std::cin >> n;
    vector<string> s(n);
    std::cin >> s;
    AC x, y;
    for (meion &t : s) {
        x.add(t);
        reverse(t);
        y.add(t);
    }
    x.work(), y.work();
    ll ans{};
    vector<ll> a(len(t) + 1);
    for (int i{}, p{}; i < len(t); ++i) {
        p = x[p][t[i] - 'a'];
        a[i + 1] = x.sz[p];
    }
    for (int i{len(t)}, p{}; i--; ) {
        p = y[p][t[i] - 'a'];
        ans += a[i] * y.sz[p];
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