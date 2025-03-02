#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> ans;
    vector<uint8_t> vis(n + 1);
    for (int i{1}; i < n + 1; ++i) {
        for (int k{i}; k < n + 1 and not vis[k]; k <<= 1) {
            vis[k] = 1;
            ans.emplace_back(k);
        }
    }
    std::cout << "2\n" << ans << '\n';
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