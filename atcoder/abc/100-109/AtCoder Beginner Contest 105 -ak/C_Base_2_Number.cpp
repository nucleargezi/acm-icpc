#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> ans;
    while (n) {
        ans.emplace_back(n & 1);
        n >>= 1;
        n += not(ans.size() & 1) and ans.back() & 1;
    }
    if (ans.size()) {
        for (int x : std::views::reverse(ans)) {
            std::cout << x;
        }
        std::cout << '\n';
    } else {
        std::cout << "0\n";
    }
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