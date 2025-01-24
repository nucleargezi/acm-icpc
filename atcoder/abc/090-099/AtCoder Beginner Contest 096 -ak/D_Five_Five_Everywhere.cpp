#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_set.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int i{11};
    vector<int> ans;
    while (ans.size() < n) {
        while (not primetest(i) or i % 10 != 1) i += 10;
        ans.emplace_back(i);
        i += 10;
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