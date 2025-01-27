#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/tree/LCA.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<int>> w(n);
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        w[--x].emplace_back(i);
    }
    vector<vector<int>> v(n);
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y), v[y].emplace_back(x);
    }
    LCA<19> lca(v, 0);
    int anc = -1;
    while (not w.empty()) {
        meion &v = w.back();
        int fa = anc;
        if (not v.empty()) {
            if (anc == -1) {
                anc = v.back(), v.pop_back();
                for (int x : v) {
                    anc = lca.lca(anc, x);
                }
            } else {
                for (int x : v) {
                    if (x != lca.lca(x, anc)) {
                        iroha std::cout << ++x << '\n', void();
                    } else {
                        fa = lca.lca(x, fa);
                    }
                }
                anc = fa;
            }
        }
        w.pop_back();
    }
    std::cout << "0\n";
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