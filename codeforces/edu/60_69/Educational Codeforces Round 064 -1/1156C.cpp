#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    int ans{};
    for (int i{0}, p{n / 2}; i < n / 2 and p < n; ++i) {
        while (a[p] - a[i] < m and p < n) ++p;
        if (p > n - 1) break;
        if (a[p] - a[i] > m - 1) {
            ++ans, ++p;
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
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}