#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    graph<int> g(n);
    g.read_tree();
    tree v(g);

    vector<int> ans(n);
    for (int i{}, p, x; i < q; ++i) {
        std::cin >> p >> x;
        ans[--p] += x;
    }
    for (int x : v.V) {
        if (v.fa[x] != -1) ans[x] += ans[v.fa[x]];
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}