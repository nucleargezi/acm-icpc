#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/euler_phi.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll a, m;
    std::cin >> a >> m;
    std::cout << euler_phi(m / GCD(a, m)) << '\n';
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