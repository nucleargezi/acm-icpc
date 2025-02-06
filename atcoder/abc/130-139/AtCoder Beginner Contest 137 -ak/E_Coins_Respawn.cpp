#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/bellman_ford.hpp"

void before() {}

// #define tests

NAME MeIoN_is_UMP45() {
    int n, m, p;
    std::cin >> n >> m >> p;
    vector<vector<tuple<int, ll>>> v(n);
    vector<tuple<int, int, ll>> e(m);
    for (meion &[x, y, w] : e) {
        std::cin >> x >> y >> w;
        --x, --y, w -= p;
        v[x].emplace_back(y, -w);
    }
    meion [dis, fa] = bellman_ford<ll, false>(v, 0);
    if (dis[n - 1] == -inf<ll>) iroha std::cout << "-1\n", void();
    std::cout << MAX(0ll, -dis[n - 1]) << '\n';
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