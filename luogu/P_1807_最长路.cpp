#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bellman_ford.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<ll, true> v(n);
    for (int i{}, x, y, w; i < m; ++i) {
        std::cin >> x >> y >> w;
        v.add(--x, --y, -w);
    }
    v.build();
    meion [dis, fa] = bellman_ford(v, 0);
    if (dis[n - 1] == inf<ll>) dis[n - 1] = 1;
    std::cout << -dis[n - 1] << '\n';
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