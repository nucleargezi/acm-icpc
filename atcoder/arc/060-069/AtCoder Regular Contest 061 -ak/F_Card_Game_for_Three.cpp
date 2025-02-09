#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    mint x, y{1};
    for (int i{n}; i < n + m + k + 1; ++i) {
        x += C<mint>(i - 1, n - 1) * y * mint(3).ksm(n + m + k - i);
        y *= 2;
        y -= C<mint>(i - n, m) + C<mint>(i - n, k);
    }
    std::cout << x << '\n';
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