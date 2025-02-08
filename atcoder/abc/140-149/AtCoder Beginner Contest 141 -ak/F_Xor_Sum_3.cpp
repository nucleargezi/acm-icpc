#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/line/vector_space.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector_space<ull> L;
    ll s{};
    for (ll i{}, x; i < n; ++i) {
        std::cin >> x;
        s ^= x;
        L.add(x);
    }
    ll msk{~s};
    vector_space<ll> LL;
    for (meion x : L.dat) {
        LL.add(x & msk);
    }
    ll x{LL.get_max()};
    std::cout << (x + (s ^ x)) << '\n';
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