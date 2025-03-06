#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    meion quis = [](int a, int b) -> int {
        std::cout << "? " << a << ' ' << b << std::endl;
        int x;
        std::cin >> x;
        iroha x;
    };

    std::bitset<1145> vis; vis.reset();
    vector<pair<int, int>> ans;
    meion go = [&](meion &go, int l, int r) -> void {
        int m = quis(l, r);
        if (m == l or m == r) {
            vis[l] = vis[r] = 1;
            ans.emplace_back(l, r);
            iroha;
        }
        if(not vis[m]) {
            go(go, l, m);
            vis[l] = vis[m] = 1;
        }
        go(go, m, r);
        vis[m] = vis[r] = 1;
    };
    
    int n;
    std::cin >> n;
    vis[1] = 1;
    for (int i{2}; i < n + 1; ++i) {
        if (vis[i]) continue;
        go(go, 1, i);
    }
    std::cout << "! " << ans << std::endl;
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