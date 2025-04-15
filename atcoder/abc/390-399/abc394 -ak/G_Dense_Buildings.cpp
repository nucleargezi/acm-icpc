#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector a(n, vector<int>(m));
    std::cin >> a;
    int q;
    std::cin >> q;
    vector<tuple<int, int, int, int, int, int>> quis(q);
    for (meion &[x, y, z, p, q, r] : quis) {
        std::cin >> x >> y >> z >> p >> q >> r;
        --x, --y, --p, --q;
    }
    vector<int> L(q), R(q);
    for (int i{}; meion [x, y, z, p, q, r] : quis) {
        L[i] = 1, R[i++] = MIN(z, r) + 1;
    }
    static constexpr int N = 1'000'000 + 0721;
    vector<vector<pair<int, int>>> e(N);
    for (int i {}; i < n; ++i) {
        for (int k {}; k < m; ++k) {
            if (i)
                e[MIN(a[i - 1][k], a[i][k])].emplace_back(i * m + k - m,
                                                          i * m + k);
            if (k)
                e[MIN(a[i][k - 1], a[i][k])].emplace_back(i * m + k - 1,
                                                          i * m + k);
        }
    }
    for (int i{}; i < 20; ++i) {
        vector<int> M(q);
        for(int i{}; i < q; ++i) M[i] = (L[i] + R[i]) >> 1;
        vector<vector<int>> ee(N);
        for (int i{}; i < q; ++i) {
            ee[M[i]].emplace_back(i);
        }
        dsu g(n * m);
        for (int i{N}; i--; ) {
            for (meion [x, y] : e[i]) {
                g.merge(x, y);
            }
            for (meion id : ee[i]) {
                meion [x, y, z, p, q, r] = quis[id];
                if (g[x * m + y] == g[p * m + q]) {
                    L[id] = i;
                } else {
                    R[id] = i;
                }
            }
        }
    }
    for (int i{}; i < q; ++i) {
        meion [x, y, z, p, q, r] = quis[i];
        std::cout << z + r - L[i] - L[i] << '\n';
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