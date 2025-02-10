#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mat.hpp"

void before() {}

#define tests
using mint = modint<mod17>;
using mat = MAT<mint, 3>;
NAME MeIoN_is_UMP45() {
    ll n;
    std::cin >> n;
    mint ans{};
    mat x(mat::mat{array<mint, 3>{0, 0, 1}, {1, 0, 0}, {0, 1, 1}});
    if (n < 4) ans = 1;
    else {
        x = x.ksm(n - 3);
        ans = x[0][2] + x[1][2] + x[2][2];
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