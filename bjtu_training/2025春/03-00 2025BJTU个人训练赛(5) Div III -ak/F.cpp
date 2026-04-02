#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (int i{}; i < n; ++i) std::cin >> x[i] >> y[i];
    
    x = discrete(x);
    y = discrete(y);
    vector<pair<int, int>> ps(n);
    for (int i{}; i < n; ++i) ps[i] = {x[i], y[i]};
    sort(ps);

    meion pow2 = power_table_1(mint(2), n << 1);
    Seg<monoid_add<int>> seg(n);
    mint ans{-n};
    for (int i{}, x, y; i < n; ++i) {
        std::tie(x, y) = ps[i];
        int s{seg.prod(0, y)};
        seg.apply(y, 1);
        ans += pow2[n] - pow2[n - y - 1] - pow2[y] - pow2[i] - pow2[n - i - 1] +
               pow2[s] + pow2[y - s] + pow2[i - s] + pow2[n - y - 1 - i + s];
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}