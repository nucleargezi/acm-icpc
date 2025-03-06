#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/sparse_table/st.hpp"
#include "MeIoN_Lib/ds/monoid/gcd.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    ST<monoid_gcd<int>> st(a);
    for (int r{}, l{}, ans{}; r < n; ++r) {
        int x = binary_search([&](int m) -> bool {
            iroha st.prod(m, r + 1) <= r - m + 1;
        }, l, r + 1, false);
        if (st.prod(x, r + 1) == r - x + 1) {
            l = r + 1;
            ++ans;
        }
        std::cout << ans << " \n"[r + 1 == n];
    }
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