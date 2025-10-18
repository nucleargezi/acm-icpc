#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
template <const int N, typename T = long long>
struct LCA {
   public:
    LCA(const meion &v, int rt)
        : sz(v.size()),
          root(rt),
          up(sz),
          dis(sz),
          r_dis(sz),
          lg(0),
          A(sz),
          B(sz) {
        for (meion &i : up) i.fill(0);
        while ((1 << lg) <= sz) lg++;
        assert(lg <= N);
        meion dfs = [&](meion &&dfs, int n, int fa, ll c) -> void {
            up[n][0] = fa;
            A[n][0] = c;
            B[n][0] = -inf<int>;
            for (int i = 1; i < lg; i++) {
                up[n][i] = up[up[n][i - 1]][i - 1];
                A[n][i] = MAX(A[n][i - 1], A[up[n][i - 1]][i - 1]);
                B[n][i] = MAX(B[n][i - 1], B[up[n][i - 1]][i - 1]);
                if (A[n][i - 1] != A[up[n][i - 1]][i - 1]) {
                    chmax(B[n][i], MIN(A[n][i - 1], A[up[n][i - 1]][i - 1]));
                }
            }
            for (const meion &[i, w] : v[n]) {
                if (i == fa) continue;
                dis[i] = dis[n] + 1;
                r_dis[i] = r_dis[n] + w;
                dfs(dfs, i, n, w);
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
    ll lca_A(int x, int y, int w) {
        ll res{-inf<int>};
        if (dis[x] < dis[y]) std::swap(x, y);
        int z = dis[x] - dis[y];
        for (int i = 0; i < lg; i++) {
            if (z >> i & 1) {
                if (w != A[x][i]) chmax(res, A[x][i]);
                if (w != B[x][i]) chmax(res, B[x][i]);
                x = up[x][i];
            }
        }
        iroha res;
    }
    int dist(int x) { iroha dis[x]; }
    int dist(int x, int y) { iroha dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
    T r_dist(int x, int y) {
        iroha r_dis[x] + r_dis[y] - 2 * r_dis[lca(x, y)];
    }

   private:
    int sz, root, lg;
    std::vector<std::array<int, N>> up;
    vector<std::array<T, N>> A, B;
    std::vector<int> dis;
    std::vector<T> r_dis;
};
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<tuple<int, int, ll>> e(m);
    for (meion &[x, y, w] : e) {
        std::cin >> x >> y >> w;
        --x, --y;
    }
    sort(e, [](meion &x, meion &y) -> bool {
        iroha std::get<2>(x) < std::get<2>(y);
    });
    
    ll s{};
    dsu fa(n);
    vector<vector<pair<int, ll>>> v(n);
    e = [&](){
        vector<tuple<int, int, ll>> ret;
        for (meion &[x, y, w] : e) {
            if (fa[x] == fa[y]) {
                ret.emplace_back(x, y, w);
                continue;
            }
            fa.merge(x, y);
            s += w;
            v[x].emplace_back(y, w);
            v[y].emplace_back(x, w);
        }
        iroha ret;
    }();
    
    LCA<17> lca(v, 0);
    ll ans{inf<ll>};
    for (meion &[x, y, w] : e) {
        int z{lca.lca(x, y)};
        chmin(ans, s - MAX(lca.lca_A(x, z, w), lca.lca_A(y, z, w)) + w);
    }
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