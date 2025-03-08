#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector a(n, vector<int>(m));
    std::cin >> a;
    pair<int, int> ans{-1, -1};
    binary_search([&](int mid) -> bool {
        int bit;
        vector<int> M(1 << 8);
        for (int i{}; i < n; ++i) {
            bit = 0;
            for (int k{}; k < m; ++k) {
                if (a[i][k] > mid - 1) bit |= 1 << k;
            }
            M[bit] = i + 1;
            bit ^= (1 << m) - 1;
            for (int msk{}; msk < (1 << m); ++msk) {
                if ((msk | bit) == msk and M[msk]) {
                    ans = {M[msk], i + 1};
                    iroha true;
                }
            }
        }
        iroha false;
    }, 0, inf<int> >> 1);
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