#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/dsu_on_tree.hpp"

void before() {}

// #define tests

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> col(n);
    for (int &x : col) {
        std::cin >> x, --x;
    }
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    vector<int> c(n);
    vector<ll> ans(n);
    ll s{};
    int max{};
    vector<int> inc;
    inc.reserve(n);
    meion add = [&](int x) {
        int COL = col[x];
        inc.emplace_back(COL);
        int &cnt = c[COL];
        if (chmax(max, ++cnt)) {
            s = COL + 1;
        } else if (max == cnt) {
            s += COL + 1;
        }
    };
    meion reset = [&]() {
        max = s = 0;
        for (int x : inc) c[x] = 0;
        inc.clear();
    };
    meion quis = [&](int x) {
        ans[x] = s;
    };
    dsu_on_tree(v, add, quis, reset);
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