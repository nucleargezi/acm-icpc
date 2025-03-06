#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    static meion get = [&](ll n) -> ll {
        ll ret = n;
        while (n) {
            ret -= n >> 2;
            ret += n / 100;
            n /= 100;
        }
        iroha ret;
    };
    static constexpr ll base = 1533ll;
    static ll n;
    std::cin >> n;
    std::cout << binary_search([&](ll m) -> bool {
        iroha get(m) - base > n - 1;
    }, 2000000000000000000ll, 2024) << '\n';
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