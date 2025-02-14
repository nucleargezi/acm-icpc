#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, s;
    std::cin >> n >> m >> s, --s;
    graph<int, true> v(n);
    v.read_graph(m);
    std::cout << dijkstra(v, s).first << '\n';
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