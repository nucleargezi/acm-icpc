#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, q);
    using X = tuple<int, int, int>;
    VEC(X, quis, q);
    vector a(n, vector<int>(m));
    for (meion &[x, y, c] : quis) --x, --y;

    meion I = [&](int x, int y) { iroha x * m + y; };
    meion O = [&](int x, int y) { iroha MIN(x, y) > -1 and x < n and y < m; };

    dsu f(n * m);
    const int N{MAX(1000, ceil(2'000'000, n * m)) + 1};
    vector<vector<X>> ads(N), lfs(N);
    int max{};
    for (int i{-1}; meion [x, y, c] : quis) {
        ++i;
        if (c == a[x][y]) continue;
        ads[c].emplace_back(x, y, i);
        lfs[a[x][y]].emplace_back(x, y, i);
        a[x][y] = c;
        chmax(max, c);
    }
    ads.resize(max + 1), lfs.resize(max + 1);

    constexpr int M{300 * 300};
    bitset<M> vis;
    int comp;
    meion clear = [&]() {
        f.rebuild();
        vis.reset();
        comp = 0;
    };
    constexpr int dx[] = {1, -1, 0, 0}, 
                  dy[] = {0, 0, 1, -1};
    meion merge = [&](int x, int y) -> void {
        ++comp;
        int id{I(x, y)};
        vis[id] = 1;
        for (int i{}, xx, yy; i < 4; ++i) {
            xx = x + dx[i], yy = y + dy[i];
            O(xx, yy) and vis[I(xx, yy)] and f.merge(I(xx, yy), id) and --comp;
        }
    };

    vector<int> ans(q + 1);
    FOR(c, max + 1) {
        if (ads[c].empty() and lfs[c].empty()) continue;
        clear();
        int pr{};
        for (meion [x, y, i] : ads[c]) {
            ans[pr] += comp, ans[i] -= comp;
            merge(x, y);
            pr = i;
        }
        clear();
        FOR(i, n) FOR(k, m) {
            c == a[i][k] and TRUE(merge(i, k));
        }
        int ls{q};
        for (meion [x, y, i] : std::views::reverse(lfs[c])) {
            ans[i] += comp, ans[ls] -= comp;
            merge(x, y);
            ls = i;
        } 
        ans[pr] += comp, ans[ls] -= comp;
    }
    for (ans.pop_back(); int x : pre_sum<false>(ans)) {
        UL(x);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}