#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/primtable.hpp"

constexpr int N = 1'000'0000;
vector prims = primtable(N);

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    ll ans{};
    FOR(i, 1, n) ans += upper(prims, n / i) - prims.begin();
    UL(ans);
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