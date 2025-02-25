#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, x;
    std::cin >> n >> x;
    vector<int> ans;
    for (int i{}; i < n; ++i) {
        if ((x | i) == x) {
            ans.emplace_back(i);
        } else {
            break;
        }
    }
    while ((int)ans.size() < n) {
        ans.emplace_back(x);
    }
    int s{};
    for (int i : ans) s |= i;
    if (s != x) {
        ans.pop_back();
        ans.emplace_back(x);
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