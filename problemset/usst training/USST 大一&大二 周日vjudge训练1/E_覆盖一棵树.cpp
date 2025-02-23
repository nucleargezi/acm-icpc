#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    for (int i{1}, fa; i < n; ++i) {
        std::cin >> fa;
        g.add(--fa, i);
    }
    g.build();
    tree v(g, 0);
    meion id = argsort(v.deep);
    vector<uint8_t> vis(n);
    int ans{};
    for (int i : id) {
        if (v.subtree_size(i) > 1) continue;
        int s{};
        while (v.fa[i] != -1 and not vis[i]) {
            ++s;
            vis[i] = 1;
            i = v.fa[i];
        };
        chmax(ans, s);
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