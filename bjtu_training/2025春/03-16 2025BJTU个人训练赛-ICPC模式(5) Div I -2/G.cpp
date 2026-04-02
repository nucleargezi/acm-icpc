#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    mint ans, x{1};
    FOR(i, n, n + m + k + 1) {
        ans += C<mint>(i - 1, n - 1) * x * mint(3).ksm(n + m + k - i);
        x *= 2;
        x -= C<mint>(i - n, m) + C<mint>(i - n, k);
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}