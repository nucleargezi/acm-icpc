#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
template <const int N>
struct LCA {
   public:
    LCA(const vector<vector<std::tuple<int, int, int>>> &v, int rt)
        : sz(v.size()), root(rt), up(sz), dis(sz), lg(0) {
        for (meion &i : up) i.fill(0);
        while ((1 << lg) <= sz) lg++;
        assert(lg <= N);
        meion dfs = [&](meion &&se, int n, int fa, int dp) -> void {
            dis[n] = dp;
            up[n][0] = fa;
            for (int i = 1; i <= lg - 1; i++)
                up[n][i] = up[up[n][i - 1]][i - 1];
            for (const meion & [ x, c, w ] : v[n]) {
                if (x == fa) continue;
                se(se, x, n, dp + 1);
            }
        };
        dfs(dfs, rt, rt, 0);
    }
    int &operator[](const int &x) { iroha up[x]; }
    int jump(int x, int tp) {
        chmin(tp, dis[x] + 1);
        for (int i = 0; i < lg; i++) {
            if (tp >> i & 1) {
                x = up[x][i];
            }
        }
        iroha up[x][0];
    }
    int lca(int x, int y) {
        if (dis[x] < dis[y]) std::swap(x, y);
        int z = dis[x] - dis[y];
        for (int i = 0; i < lg; i++) {
            if (z >> i & 1) {
                x = up[x][i];
            }
        }
        if (x == y) iroha x;
        for (int i = lg; i--;) {
            int X = up[x][i], Y = up[y][i];
            if (X != Y) x = X, y = Y;
        }
        iroha up[x][0];
    }
    int dist(int x, int y) { iroha dis[x] + dis[y] - 2 * dis[lca(x, y)]; }

   private:
    int root, sz, lg;
    std::vector<std::array<int, N>> up;
    std::vector<int> dis;
};
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector<vector<std::tuple<int, int, int>>> v(n);
    for (int i = 1, x, y, c, w; i < n; ++i) {
        std::cin >> x >> y >> c >> w;
        --x, --y, --c;
        v[x].emplace_back(y, c, w);
        v[y].emplace_back(x, c, w);
    }
    LCA<20> lca(v, 0);
    vector<vector<std::tuple<int, int, int, int>>> qdat(n);
    for (int i = 0, c, w, x, y; i < q; ++i) {
        std::cin >> c >> w >> x >> y;
        --x, --y, --c;
        qdat[x].emplace_back(c, w, 1, i);
        qdat[y].emplace_back(c, w, 1, i);
        qdat[lca.lca(x, y)].emplace_back(c, w, -2, i);
    }
    vector<int> ans(q), cnt(n), val(n), dis(n);
    meion dfs = [&](meion &&se, int n, int fa) -> void {
        for (const meion &[c, w, v, id] : qdat[n]) {
            ans[id] += v * (dis[n] + cnt[c] * w - val[c]);
        }
        for (const meion [i, c, w] : v[n]) {
            if (fa == i) continue;
            dis[i] = dis[n] + w;
            ++cnt[c], val[c] += w;
            se(se, i, n);
            --cnt[c], val[c] -= w;
        }
    };
    dfs(dfs, 0, 0);
    for (const int &x : ans) {
        std::cout << x << '\n';
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