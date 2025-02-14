#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/maxflow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    --s, --t;
    max_flow<ll> FL(n, s, t);
    for (int i{}, x, y, w; i < m; ++i) {
        std::cin >> x >> y >> w;
        --x, --y;
        FL.add(x, y, w);
    }
    std::cout << FL.flow() << '\n';
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