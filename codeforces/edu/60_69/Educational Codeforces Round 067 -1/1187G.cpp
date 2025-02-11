#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, K, c, d;
    std::cin >> n >> m >> K >> c >> d;
    meion id = [&](int x, int y) { iroha n * x + y; };
    int tt{n + K + 1}, s{id(tt, 0)}, t{s + 1};
    mcf_graph FL(t + 1);
    for (int i{}, x; i < K; ++i) {
        std::cin >> x;
        FL.add(s, id(0, --x), 1, 0);
    }
    for (int i{}; i < tt; ++i) {
        FL.add(id(i, 0), t, K, c * i);
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < tt - 1; ++k) {
            FL.add(id(k, i), id(k + 1, i), K, 0);
        }
    }
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --x, --y;
        for (int i{}; i < 2; ++i, std::swap(x, y)) {
            for (int i{}; i < tt - 1; ++i) {
                for (int k{}; k < K; ++k) {
                    FL.add(id(i, x), id(i + 1, y), 1, (k << 1 | 1) * d);
                }
            }
        }
    }
    std::cout << FL.flow(s, t).second << '\n';
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