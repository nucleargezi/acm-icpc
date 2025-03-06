#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector a(n, vector<int>(m));
    std::cin >> a;
    std::cout << binary_search([&](ll mid) -> bool {
        vector<int> v(n), vv(m);
        for (int i{}; i < n; ++i) {
            for (int k{}; k < m; ++k) {
                if (a[i][k] > mid - 1) {
                    ++v[i], vv[k] = 1;
                }
            }
        }
        bool f{false}, ff{true};
        for (int x : v) {
            f |= x > 1;
        }
        for (int x : vv) {
            ff &= not not x;
        }
        iroha ff and f;
    }, 1, inf<int> / 2) << '\n';
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