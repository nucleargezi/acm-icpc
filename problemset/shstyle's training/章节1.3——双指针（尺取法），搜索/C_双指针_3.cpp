#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, k, q;
    std::cin >> n >> k >> q;
    vector<int> a(n);
    std::cin >> a;
    ll ans{};
    for (int l{}, r{}; l < n; ++l, chmax(r, l)) {
        if (a[l] > q) continue;
        while (r < n and a[r] < q + 1) ++r;
        ans += MAX(0, r - l - k + 1);
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