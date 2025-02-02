#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    mint x, y, ans;
    for (int i{1}; i < n; ++i) {
        x += mint(n - i) * 2 * i;
    }
    for(int i{1}; i < m; ++i) {
        y += mint(m - i) * 2 * i;
    }
    ans = x * m * m + y * n * n;
    std::cout << ans * C<mint>(n * m - 2, k - 2) / 2 << '\n';
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