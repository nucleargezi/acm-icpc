#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum<false>(a);
    ll ans{a[n - 1] * K};
    a.pop_back();
    sort(a);
    a.resize(--K);
    std::cout << ans - qsum(a, 0ll) << '\n';
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