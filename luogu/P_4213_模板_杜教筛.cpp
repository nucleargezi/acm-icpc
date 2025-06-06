#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/du.hpp"

void before() {}

#define tests
pre_phi_sum X;
pre_mu_sum Y;
NAME MeIoN_is_UMP45() {
    LL(n);
    UL(X(n), Y(n));
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}