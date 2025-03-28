#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/fibonacci_search.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, d;
    std::cin >> n >> d;
    for (int i{}; i * i < d + 1; ++i) {
        if (i + ceil(d, i + 1) < n + 1) iroha YES();
    }
    NO();
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