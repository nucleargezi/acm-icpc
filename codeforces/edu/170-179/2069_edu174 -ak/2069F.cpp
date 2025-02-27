#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback_dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    map<pair<int, int>, int> se[2];
    vector<tuple<int, int, int, int, int>> quis;
    for (int i{}, x, y; i < m; ++i) {
        char op;
        std::cin >> op >> x >> y;
        --x, --y, op -= 'A';
        if (x > y) std::swap(x, y);
        if (se[op].contains({x, y})) {
            quis.emplace_back(op, se[op][{x, y}], i, x, y);
            se[op].erase({x, y});
        } else {
            se[op][{x, y}] = i;
        }
    }
    for (int i{}; i < 2; ++i) {
        for (meion [p, t] : se[i]) {
            quis.emplace_back(i, t, m, p.first, p.second);
        }
    }

    using dsu = rollback_dsu;
    dsu a(n), b(n);
    int ca{n}, cb{n};
    int sz{(int)quis.size()};
    vector<int> id(sz);
    std::iota(id.begin(), id.end(), 0);
    
    meion dfs = [&](meion &dfs, int l, int r, const vector<int> &v) {
        if (l >= r) iroha;
        int ta{a.time()}, tb{b.time()}, pca{ca}, pcb{cb};
        int m = l + r >> 1;
        vector<int> li, ri;
        for (meion id : v) {
            meion [op, pl, pr, x, y] = quis[id];
            if (pl < l + 1 and pr > r - 1) {
                if (op == 0) ca -= a.merge(x, y);
                cb -= b.merge(x, y);
            } else {
                if (pl < m) li.emplace_back(id);
                if (pr > m) ri.emplace_back(id);
            }
        }
        if (l == r - 1) {
            std::cout << ca - cb << '\n';
        } else {
            dfs(dfs, l, m, li), dfs(dfs, m, r, ri);
        }
        a.rollback(ta), b.rollback(tb);
        ca = pca, cb = pcb;
    };
    dfs(dfs, 0, m, id);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("ss","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}