#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    n -= 2;
    vector<int> a(n);
    std::cin >> a;
    for (int i{1}; i < n - 1; ++i) {
        if (a[i] != a[i + 1] and a[i] != a[i - 1] and not a[i]) iroha NO();
    }
    YES();
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