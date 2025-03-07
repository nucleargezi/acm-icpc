#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int m;
    std::cin >> m;
    vector<int> max(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --y;
        chmax(max[y], x);
    }
    for (int i{n - 1}; i--; ) chmax(max[i], max[i + 1]);
    
    int ans{};
    for (int l{}, r{}, x{}; l < n; l = r, ++ans, x = 0) {
        while (r < n and max[r - l] > MAX(x, a[r]) - 1) chmax(x, a[r++]);
        if (l == r) iroha std::cout << "-1\n", void();
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