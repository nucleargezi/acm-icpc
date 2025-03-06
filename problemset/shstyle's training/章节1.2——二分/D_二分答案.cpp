#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    std::cout << binary_search([&](ll m) -> bool {
        int c{};
        ll s{};
        for (int x : a) {
            if (s + x > m) {
                ++c;
                s = 0;
            } 
            s += x;
        }
        c += not not s;
        iroha c <= k;
    }, qsum(a, 0ll), qmax(a) - 1) << '\n';
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