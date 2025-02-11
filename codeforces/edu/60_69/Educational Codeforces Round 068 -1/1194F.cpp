#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    ll n, t;
    std::cin >> n >> t;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum<false>(a);
    vector pow = power_table_1<mint>(mint(2).inv(), n);
    mint ans, s{1};
    ll x{}, y{};
    for (int i{}; i < n and a[i] < t + 1; ++i) {
        s += s + C<mint>(x++, ++y);
        ll d{t - a[i]};
        if (d > x - 1) {
            ans += 1;
            continue;
        }
        while (d < y) {
            s -= C<mint>(x, y--);
        }
        ans += s * pow[i + 1];
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