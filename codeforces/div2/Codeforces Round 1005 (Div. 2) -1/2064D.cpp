#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector<int> a(n);
    std::cin >> a;
    
    vector<int> bit[32];
    for (int k{}; k < 30; ++k) {
        bit[k].resize(n);
        for (int i{}; i < n; ++i) {
            bit[k][i] += a[i] >> k & 1;
        }
        rev(bit[k]);
        bit[k] = pre_sum(bit[k]);
        rev(bit[k]);
    }
    a.emplace_back(0);
    for (int i{n}; i--; ) a[i] ^= a[i + 1];
    
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        int lim = -1;
        int ans{inf<int>};
        for (int i{30}, R{n}; i--; ) {
            if (x >> i & 1) {
                int L = binary_search([&](int m) {
                    if (m == lim) iroha true;
                    iroha bit[i][m] - bit[i][R] > 1;
                }, lim, n);
                if (L != lim) {
                    chmin(ans, n - L - 1);
                    lim = L;
                }
                L = binary_search([&](int m) {
                    if (m == lim) iroha true;
                    iroha bit[i][m] - bit[i][R] > 0;
                }, lim, n);
                if (L == lim) {
                    chmin(ans, n - L - 1);
                    break;
                } else {
                    x ^= a[L + 1] ^ a[R];
                    R = L + 1;
                }
            } else {
                int L = binary_search([&](int m) {
                    if (m == lim) iroha true;
                    iroha bit[i][m] - bit[i][R] > 0;
                }, lim, n);
                lim = L;
                chmin(ans, n - L - 1);
            }
        }
        std::cout << ans << " \n"[i + 1 == q];
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