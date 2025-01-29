#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a, b;
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        (x > 0 ? a : b).emplace_back(ABS(x));
    }
    bool f{b.size() & 1};
    a.insert(a.end(), b.begin(), b.end());
    sort(a);
    std::cout << (f ? qsum(a, 0ll) - a[0] - a[0] : qsum(a, 0ll)) << '\n';
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