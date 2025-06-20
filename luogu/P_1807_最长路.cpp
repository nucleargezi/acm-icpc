#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bellman_ford.hpp"

void before() {}

// #define tests
void Yorisou() {
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