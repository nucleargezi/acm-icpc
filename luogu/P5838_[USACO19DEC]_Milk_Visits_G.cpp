#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> c(n);
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        c[--x].emplace_back(i);
    }
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_add<int>> seg(v);

    vector<tuple<int, int, int, int>> q(m);
    for (int t{}; meion &[w, x, y, id] : q) {
        std::cin >> x >> y >> w;
        --x, --y, --w;
        id = t++;
    }
    string ans(m, '0');

    sort(q);
    for (int pr = -1; meion &[w, x, y, id] : q) {
        if (pr != w) {
            if (pr != -1) {
                for (int id : c[pr]) {
                    seg.set(id, 0);
                }
            }
            pr = w;
            for (int id : c[pr]) {
                seg.set(id, 1);
            }
        }
        ans[id] += not not seg.prod_path(x, y);
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}