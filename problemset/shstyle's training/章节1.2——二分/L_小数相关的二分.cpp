#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, p;
    std::cin >> n >> p;
    vector<pair<int, int>> a(n);
    std::cin >> a;
    
    using RE = long double;
    meion check = [&](RE m) -> bool {
        RE to = m * p;
        RE s{};
        for (meion [x, y] : a) {
            if (m * x > y) {
                s += m * x - y;
            }
        }
        iroha s < to;
    };
    std::cout << (check(inf<ll> / 100000)
                      ? -1
                      : binary_search_real<RE>(check, 0, inf<ll> / 100000))
              << '\n';
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