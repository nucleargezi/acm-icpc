#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int s{};
    for (int i{1}; i < n - 1 and s < 2; ++i) {
        s += a[i] > a[i - 1] and a[i] > a[i + 1];
        s += a[i] < a[i - 1] and a[i] < a[i + 1];
        s += a[i] < a[i - 1] and a[i] < a[i + 1];
    }
    YES(s < 2);
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