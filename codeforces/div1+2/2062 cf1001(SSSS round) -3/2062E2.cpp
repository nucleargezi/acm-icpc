#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
struct Fenw {
    int n;
    vector<ll> v;
    Fenw(int n) : n(n + 1), v(n + 1) {}
    meion add(int i, ll x) -> void {
        for (; i < n; i += lowbit(i)) {
            v[i] += x;
        }
    }
    meion quis(int i) -> ll {
        ll res{};
        for (; i; i -= lowbit(i)) {
            res += v[i];
        }
        iroha res;
    }
};
template <const int N>
struct LCA {
   public:
    LCA(const vector<vector<int>> &v, int rt)
        : sz(v.size()), root(rt), up(sz), dis(sz), L(sz), R(sz), id(sz), lg(0) {
        for (meion &i : up) i.fill(0);
        while ((1 << lg) <= sz) lg++;
        assert(lg <= N);
        int t{};
        meion dfs = [&](meion &&dfs, int n, int fa) -> void {
            id[t] = n;
            L[n] = ++t;
            up[n][0] = fa;
            for (int i = 1; i < lg; i++)
                up[n][i] = up[up[n][i - 1]][i - 1];
            for (const meion &i : v[n]) {
                if (i == fa) continue;
                dis[i] = dis[n] + 1;
                dfs(dfs, i, n);
            }
            R[n] = t;
        };
        dfs(dfs, rt, rt);
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
    int dist(int x) { iroha dis[x]; }
    int dist(int x, int y) { iroha dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
    meion Throw() { iroha tuple {L, R, id}; }

   private:
    int root, sz, lg;
    std::vector<std::array<int, N>> up;
    std::vector<int> dis;
    std::vector<int> L, R, id;
};
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
    meion [L, R, id] = lca.Throw();
    Fenw g(n), gg(n);
    set<int> se;
    vector<int> ans;
    int s{}, need{};
    for (int nw{n}; nw--; ) {
        vector<int> go;
        for (int i : w[nw]) {
            int d = g.quis(R[i]) - g.quis(L[i]);
            if (d != s) {
                go.emplace_back(i);
                d = gg.quis(R[i]) - gg.quis(L[i] - 1);
                if (d == need) {
                    ans.emplace_back(i);
                }
            }
        }
        for (int i : go) {
            int anc{-1};
            set<int> go{*se.begin(), *se.rbegin()};
            if (se.lower_bound(R[i] + 1) != se.end())
                go.emplace(*se.lower_bound(R[i] + 1));
            if (se.lower_bound(L[i]) != se.begin()) {
                go.emplace(*--se.lower_bound(L[i]));
            }
            for (int y : go) {
                if (y < L[i] or y > R[i]) {
                    if (anc == -1) anc = id[y - 1];
                    anc = lca.lca(anc, id[y - 1]);
                }
            }
            gg.add(L[i], 1);
            gg.add(L[anc], 1);
            anc = lca.lca(i, anc);
            gg.add(L[anc], -1);
            ++need;
        }
        for (int x : w[nw]) {
            g.add(L[x], 1);
            se.emplace(L[x]);
            ++s;
        }
    }
    sort(ans);
    std::cout << ans.size();
    for (int x : ans) {
        std::cout << ' ' << ++x;
    }
    std::cout << '\n';
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