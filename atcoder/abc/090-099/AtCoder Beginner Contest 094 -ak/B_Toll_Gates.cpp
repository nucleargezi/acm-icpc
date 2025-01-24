#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, x;
    std::cin >> n >> m >> x;
    vector<int> a(n);
    for (int i{}, x; i < m; ++i) {
        std::cin >> x, --x;
        ++a[x];
    }
    std::cout << MIN(std::accumulate(a.begin(), a.begin() + x, 0),
                     std::accumulate(a.begin() + x, a.end(), 0))
              << '\n';
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