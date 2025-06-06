#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    VEC(ll, a, n);
    a = pre_sum(a);
    ll l{binary_search([&](ll p) -> bool {
        iroha a[p] < a[n] / 2 + 1;
    }, 0, n + 1)}, r{n - l};
    if (l != n and a[l] <= a[n] - a[l + 1]) ++l, --r;
    UL(l, r);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}