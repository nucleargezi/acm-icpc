#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

void before() {}

// #define tests
using mint = dmint;
NAME MeIoN_is_UMP45() {
    int mod;
    std::cin >> mod;
    mint::set_mod(mod);
    vector<mint> a(mod), ans(mod);
    std::cin >> a;
    ans[0] = a[0];
    for (int i{}; i < mod - 1; ++i) {
        for (int k{}; k < mod; ++k) {
            ans[mod - 1 - i] += a[k];
            a[k] *= k;
        }
    }
    for (int i{1}; i < mod; ++i) {
        ans[i] *= mod - 1;
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