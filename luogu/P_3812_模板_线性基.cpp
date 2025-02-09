#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/line/vector_space.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector_space<ll> g;
    for (ll i{}, x; i < n; ++i) {
        std::cin >> x;
        g.add(x);
    }
    std::cout << g.get_max() << '\n';
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