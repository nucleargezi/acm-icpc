#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

struct dsu{
   public:
    dsu(int _n) : n(_n), comp(_n), fa(_n), sz(_n, 1) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    int operator[](int x) { iroha ff(x); }
    int size(int x) { iroha sz[ff(x)]; }
    int get_comp() { iroha comp; }
    void merge(int x, int y) {
        fa[x] = ff(y);
    }
    void rebuild() {
        std::iota(fa.begin(), fa.end(), 0);
        fill(sz, 1);
    }

   private:
    int n, comp;
    std::vector<int> fa, sz;
    int ff(int x) {
        iroha (fa[x] == x ? x : (fa[x] = ff(fa[x])));
    }
};

NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<int> g(n);
    g.read_tree();
    tree v(g);

    vector<tuple<int, int, int>> e(m);
    for (int t{}; meion &[w, x, y] : e) {
        std::cin >> x >> y >> w;
        --x, --y;
    }
    sort(e);
    
    vector<int> ans(n - 1, -1);
    dsu UN(n);
    for (int lca; meion &[w, x, y] : e) {
        lca = v.LCA(x, y);
        x = UN[x], y = UN[y];
        while (v.deep[x] > v.deep[lca]) {
            ans[v.VtoE[x]] = w;
            UN.merge(x, v.fa[x]);
            x = UN[v.fa[x]];
        }
        while (v.deep[y] > v.deep[lca]) {
            ans[v.VtoE[y]] = w;
            UN.merge(y, v.fa[y]);
            y = UN[v.fa[y]];
        }
    }
    for (int x : ans) std::cout << x << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}