#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_rev.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    constexpr int N = 20;
    vector<pair<ll, ll>> v[N];
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        for (int i{}; i < N; ++i) {
            v[i].emplace_back(x >> i & 1, x >> i & 1 ^ 1);
        }
    }
    lazy_seg<a_monoid_sum_rev<pair<ll, ll>>> seg[N];
    for (int i{}; i < N; ++i) {
        seg[i].build(v[i]);
    }

    int q;
    std::cin >> q;
    for (int i{}, op, l, r, x; i < q; ++i) {
        std::cin >> op >> l >> r, --l;
        if (op == 1) {
            ll ans{};
            for (int i{}; i < N; ++i) {
                ans += (1 << i) * seg[i].prod(l, r).first;
            }
            std::cout << ans << '\n';
        } else {
            std::cin >> x;
            for (int i{}; i < N; ++i) {
                x >> i & 1 and TRUE(seg[i].apply(l, r, true));
            }
        }
    }
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