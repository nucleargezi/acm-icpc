#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, k, l1, r1, l2, r2);
    if (l1 > l2) std::swap(l1, l2), std::swap(r1, r2);
    if (l1 == l2 and r1 > r2) std::swap(r1, r2);
    if (r1 > r2) {
        k -= (r2 - l2) * n;
        r1 -= r2 - l2;
        l2 = r2 = l1;
    } else if (r1 > l2) {
        k -= (r1 - l2) * n;
        r2 -= r1 - l2;
        r1 = l2;
    }
    if (k < 1) iroha UL(0);
    ll x{ABS(l1 - l2) + ABS(r1 - r2)}, y{MAX(r1, r2) - MIN(l1, l2)};
    if (y) {
        ll a{k / y}, b{k % y};
        chmin(a, n);
        b = k - a * y;
        ll ans{inf<ll>};
        a and chmin(ans, x * a + b * 2);
        a < n and b < y and chmin(ans, x * (a + 1) - y + b);
        UL(ans);
    } else UL(k << 1);
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