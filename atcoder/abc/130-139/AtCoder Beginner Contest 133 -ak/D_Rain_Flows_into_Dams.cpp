#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    vector<ll> ans(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            s -= a[i];
        } else {
            s += a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = s;
        s = a[i] * 2 - s;
    }
    std::cout << ans << '\n';
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