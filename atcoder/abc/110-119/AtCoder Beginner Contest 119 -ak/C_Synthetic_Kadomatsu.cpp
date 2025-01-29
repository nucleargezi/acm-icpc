#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, A, B, C;
    std::cin >> n >> A >> B >> C;
    vector<int> v(n);
    std::cin >> v;
    int ans {inf<int>};
    for (int msk {}; msk < (1 << n * 2); ++msk) {
        int a = 0, b = 0, c = 0;
        int aa = 0, bb = 0, cc = 0;
        for (int bit{}; bit < n; bit++) {
            if (msk & (1 << 2 * bit) and msk & (1 << (2 * bit + 1))) {
                a += v[bit];
                aa++;
            }
            if (msk & (1 << 2 * bit) and not(msk & (1 << (2 * bit + 1)))) {
                b += v[bit];
                bb++;
            }
            if (not(msk & (1 << 2 * bit)) and msk & (1 << (2 * bit + 1))) {
                c += v[bit];
                cc++;
            }
        }
        if (a and b and c) {
            chmin(ans, ABS(A - a) + ABS(B - b) + ABS(C - c) +
                           (aa + bb + cc - 3) * 10);
        }
    }
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
    while (T--) {
        MeIoN_is_UMP45();
    }
    iroha 0;
}