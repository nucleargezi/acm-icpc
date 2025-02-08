#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<pair<int, int>>> v(n);
    for (int i{}, sz; i < n; ++i) {
        std::cin >> sz;
        v[i].resize(sz);
        for (meion &[x, y] : v[i]) {
            std::cin >> x >> y, --x;
        }
    }
    int ans{};
    for (int msk{}; msk < (1 << n); ++msk) {
        bool ok = true;
        for (int bit{}; bit < n and ok; ++bit) {
            if (msk >> bit & 1) {
                for (meion [x, y] : v[bit]) {
                    ok &= not(y ^ ((msk & (1 << x)) > 0));
                }
            }
        }
        if (ok) chmax(ans, popcount(msk));
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
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}