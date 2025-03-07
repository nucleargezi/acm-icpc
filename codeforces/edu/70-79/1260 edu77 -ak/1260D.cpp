#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int m, n, k, t;
    std::cin >> m >> n >> k >> t;
    vector<int> a(m);
    vector<tuple<int, int, int>> trap(k);
    std::cin >> a >> trap;
    sort(a, greater());
    std::cout << binary_search([&](ll m) -> bool {
        if (not m) iroha true;
        vector<int> c(n + 1);
        for (meion [l, r, d] : trap) {
            if (a[m - 1] < d) c[--l] += 1, --c[r];
        }
        c = pre_sum<false>(c);
        int s{};
        for (int i : c) {
            s += i > 0 ? 3 : 1;
        }
        iroha s < t + 1;
    }, 0, m + 1) << '\n';
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