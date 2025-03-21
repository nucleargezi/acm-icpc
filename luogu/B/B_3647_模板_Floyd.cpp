#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/floyd.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<tuple<int, int, ll>> e(m);
    for (meion &[x, y, w] : e) {
        std::cin >> x >> y >> w;
        --x, --y;
    }
    meion dis = floyd<100>(e, n);
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cout << dis[i][k] << " \n"[k + 1 == n];
        }
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