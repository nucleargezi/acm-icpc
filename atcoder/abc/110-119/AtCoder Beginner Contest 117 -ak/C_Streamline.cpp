#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int m, n;
    std::cin >> m >> n;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    vector<int> d;
    for (int i{1}; i < n; ++i) {
        d.emplace_back(a[i] - a[i - 1]);
    }
    sort(d);
    d.emplace_back(0);
    int ans{};
    std::cout << std::accumulate(d.begin(), d.begin() + MAX(0, n - m), 0ll) << '\n';
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