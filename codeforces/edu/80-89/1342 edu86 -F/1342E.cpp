#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    LL(n, k);
    if (k > n - 1) iroha UL(0);
    
    mint ans;
    FOR(i, n - k + 1) {
        ans += mint((n - k - i & 1) ? -1 : 1) * C<mint>(n - k, i) * mint(i).ksm(n);
    }
    UL(ans * C<mint>(n, n - k) * (1 + not not k));
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