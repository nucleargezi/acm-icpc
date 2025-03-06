#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    string ans{};
    vector<int> seg;
    while (n) {
        ll l = binary_search([&](ll m) -> bool {
            iroha m * (m - 1) / 2 < n + 1;
        }, 2, n + 0721);
        n -= l * (l - 1) / 2;
        seg.emplace_back(l);
    }
    ans += '7';
    for (int pr{}; int l : std::ranges::views::reverse(seg)) {
        ans += string(l - pr, '3') + '1';
        pr = l;
    }
    reverse(ans);
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("in","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}