#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    priority_queue<int> q;
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        q.emplace(x);
    }
    while (m--) {
        meion x = q.top();
        q.pop();
        q.emplace(x >> 1);
    }
    ll ans{};
    while (not q.empty()) {
        ans += q.top();
        q.pop();
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