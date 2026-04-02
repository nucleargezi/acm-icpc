#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

// #define tests
using mint = dmint;
NAME MeIoN_is_UMP45() {
    int mod;
    std::cin >> mod;
    mint::set_mod(mod);
    vector<mint> a(mod), ans(a);
    std::cin >> a;
    for (int i{}; i < mod; ++i) {
        if (not a[i].val) continue;
        ans[0] += 1;
        mint bas{1};
        for (int k{mod}; k--; ) {
            ans[k] -= bas * C<mint>(mod - 1, k);
            bas *= -i;
        }
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
#ifdef tests
std::cin >> T;
#endif
while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}