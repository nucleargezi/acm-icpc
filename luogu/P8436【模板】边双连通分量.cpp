#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/scc.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    for (int i{}, t{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y, i);
        v[y].emplace_back(x, i);
    }
    meion [dcc, id] = get_dcc_undir(v);
    std::cout << dcc.size() << '\n';
    for (meion &v : dcc) {
        std::cout << v.size();
        for (meion &x : v) {
            std::cout << ' ' << ++x;
        }
        std::cout << '\n';
    }
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