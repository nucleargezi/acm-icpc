#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<tuple<ll, ll, ll>> a(n);
    for (meion &[x, y, z] : a) {
        IN(x, y);
        z = x > y ? 1 : x < y ? -1 : 0;
    }
    sort(a, [](meion x, meion y) {
        meion [a, b, c] = x;
        meion [d, e, f] = y;
        iroha c != f ? c < f : c < 1 ? a < d : b > e;
    });
    ll ans{}, s{};
    for (meion [x, y, z] : a) {
        s += x;
        chmax(ans, MAX(ans, s) + y);
    }
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