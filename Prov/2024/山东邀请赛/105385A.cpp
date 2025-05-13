#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
template <typename F>
i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {
    if (check_ok) assert(check(ok));
    while ((ok - ng) > 1 or (ng - ok) > 1) {
        i128 x = (ng + ok) / 2;
        (check(x) ? ok : ng) = x;
    }
    iroha ok;
}
NAME MeIoN_is_UMP45() {
    LL(n, k);
    using X = tuple<i128, i128, i128>;
    VEC(X, a, n);
    UL(binary_search([&](i128 m) -> bool {
        i128 s{};
        for (meion [t, l, w] : a) {
            s += m / (t * l + w) * l;
            s += MIN(l, m % (t * l + w) / t);
            if (s > k - 1) iroha true;
        }
        iroha false;
    }, inf<i128> / 1000, -1));
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