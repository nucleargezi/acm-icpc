#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/tree/LCA.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, s, t;
    std::cin >> n >> s >> t, --s, --t;
    vector<vector<int>> v(n);
    for (int i{1}, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    LCA<17> lca(v, 0);
    int ans{};
    for (int i{}; i < n; ++i) {
        if (lca.dist(s, i) < lca.dist(t, i)) {
            chmax(ans, lca.dist(t, i));
        }
    }
    std::cout << --ans << '\n';
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