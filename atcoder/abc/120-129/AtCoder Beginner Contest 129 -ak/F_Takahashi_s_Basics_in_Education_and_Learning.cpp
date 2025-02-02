#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"
#include "MeIoN_Lib/math/mat.hpp"

void before() {}

// #define tests
using mint = dmint;
using mat = MT<mint, 3>;
NAME MeIoN_is_UMP45() {
    ll l, a, b, mod;
    std::cin >> l >> a >> b >> mod;
    mint::set_mod(mod);
    mat ans;
    ans[0][0] = 0;
    ans[1][0] = a - b;
    ans[2][0] = 1;
    ll s{};
    for (ll i{1}, base{10}; i < 19 and s != l; ++i, base *= 10) {
        ll cnt{};
        if (base - 1 < a) continue;
        if (base / 10 - 1 < a and a < base)
            cnt = (base - 1 - a) / b + 1;
        else
            cnt = (base - 1 - a) / b - (base / 10 - 1 - a) / b;
        chmin(cnt, l - s);
        mat mt;
        mt[0][0] = base;
        mt[0][1] = mt[1][1] = mt[2][2] = 1;
        mt[0][2] = mt[1][2] = b;
        mt.ksm(cnt, true);
        mt *= ans;
        for (int i{}; i < 3; ++i) ans[i][0] = mt[i][0];
        s += cnt;
    }
    std::cout << ans[0][0].val << '\n';
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