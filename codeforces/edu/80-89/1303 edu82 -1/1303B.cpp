#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, g, b);

    ll d{ceil(n, 2) / g}, L{ceil(n, 2) % g};
    not L and TRUE(--d, L += g);

    n -= d * MIN(g + g, g + b) + L;
    n -= MIN(MAX(MIN(L, b - g), 0ll) * d, n);

    std::cout << d * (g + b) + L + n << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(T);
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}