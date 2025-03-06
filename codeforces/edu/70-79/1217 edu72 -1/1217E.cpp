#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

void before() {}

// #define tests

struct minmin {
    using value_type = pair<ll, ll>;
    using X = value_type;
    static X op(X x, X y) {
        if (x.first > y.first) std::swap(x, y);
        iroha {x.first, MIN(x.second, y.first)};
    }
    static constexpr X unit() { iroha {inf<ll>, inf<ll>}; }
    static constexpr bool commute = 1;
};
NAME MeIoN_is_UMP45() {
    constexpr ll bas[] = {1,           10,           100,       1000,
                          1000'0,      100'000,      1'000'000, 10'000'000,
                          100'000'000, 1'000'000'000};
    int n, q;
    std::cin >> n >> q;
    vector<ll> a(n);
    std::cin >> a;
    Seg<minmin> seg[9];
    for (int i{}; i < 9; ++i) {
        vector<pair<ll, ll>> v(n);
        for (int k{}; k < n; ++k) {
            int bit{a[k] / bas[i] % 10};
            v[k] = {bit ? a[k] : inf<ll>, inf<ll>};
        }
        seg[i].build(v);
    }
    for (int i{}, op, x, y; i < q; ++i) {
        std::cin >> op >> x >> y, --x;
        if (op == 1) {
            for (int i{}; i < 9; ++i) {
                ll bit{y / bas[i] % 10};
                seg[i].set(x, {bit ? y : inf<ll>, inf<ll>});
            }
        } else {
            ll ans{inf<ll>};
            for (int i{}; i < 9; ++i) {
                meion [l, r] = seg[i].prod(x, y);
                if (MAX(l, r) != inf<ll>) chmin(ans, l + r);
            }
            std::cout << (ans == inf<ll> ? -1 : ans) << '\n';
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