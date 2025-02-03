#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<int> v(a);
    sort(v);
    for (int i{}; i < n; ++i) {
        for (int k{i + 1}; k < n; ++k) {
            std::swap(a[i], a[k]);
            if (a == v) iroha YES();
            std::swap(a[i], a[k]);
        }
    }
    YES(a == v);
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