#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion quis = [](const meion &v) -> ll {
        std::cout << "? " << v << std::endl;
        ll res;
        std::cin >> res;
        iroha res;
    };
    meion answer = [](ll ans) -> void {
        std::cout << "! " << ans << std::endl;
    };

    constexpr int N = 100;
    array<int, N> a;
    ll q{};
    for (int i{}; i < 7; ++i) q |= 1ll << i;
    for (int i{}; i < 100; ++i) a[i] = q + (1ll << 7) * i;
    ll l = quis(a);
    q = 0;
    for (int i{7}; i < 14; ++i) q |= 1ll << i;
    for (int i{}; i < 100; ++i) a[i] = q + i;
    ll r = quis(a);

    ll ans{};
    for (int i{}; i < 14; ++i) {
        ans ^= ((i < 7 ? l : r) >> i & 1 ^ 1) << i;
    }
    answer(ans);
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