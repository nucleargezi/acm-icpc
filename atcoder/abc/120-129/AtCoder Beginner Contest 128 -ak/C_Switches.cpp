#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a[m];
    for (int i{}, sz; i < m; ++i) {
        std::cin >> sz;
        a[i].resize(sz);
        std::cin >> a[i];
    }
    vector<int> p(m);
    std::cin >> p;
    int ans{};
    for (int msk{}; msk < (1 << n); ++msk) {
        int s{};
        for (int i{}, x; i < m; ++i) {
            x = p[i];
            for (int y : a[i]) {
                x ^= msk >> y - 1 & 1;
            }
            s += not x;
        }
        ans += s == m;
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