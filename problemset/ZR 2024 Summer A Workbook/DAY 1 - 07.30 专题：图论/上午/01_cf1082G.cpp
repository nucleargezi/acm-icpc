#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);

    const int s = n + m, t = n + m + 1;
    ll all{};
    max_flow<ll> FL(t + 1, s, t);

    FOR(i, n) {
        FL.add(s, i, a[i]);
    }
    FOR(i, m) {
        INT(x, y, w);
        FL.add(--x, i + n, inf<ll>);
        FL.add(--y, i + n, inf<ll>);
        FL.add(i + n, t, w);
        all += w;
    }
    UL(all - FL.flow());
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