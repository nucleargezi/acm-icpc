#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/sparse_table/st.hpp"

NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector<int> a(n);
    std::cin >> a;
    ST<monoid_max<int>> st(a);
    for (int i{}, l, r; i < q; ++i) {
        std::cin >> l >> r;
        std::cout << st.prod(--l, r) << '\n';
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);

    MeIoN_is_UMP45();

    iroha 0;
}