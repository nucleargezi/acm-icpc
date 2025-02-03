#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<int> ans(n);
    for (int i = n; i--; ) { 
        ans[i] = a[i];
        for (int k = (i + 1) * 2; k < n + 1; k += i + 1) {
            if (ans[k - 1]) {
                ans[i] ^= 1;
            }
        }
    }
    std::cout << qsum(ans, 0) << '\n';
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';
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