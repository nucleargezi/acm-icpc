#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    ll s{};
    FOR(i, n) s += (i + 1) * a[i];
    a = pre_sum(a);
    using F = Line<ll>;
    constexpr int N = 1'000'000;
    lichao_tree seg(-N, N + 1, F{0, 0});
    FOR(i, 1, n + 1) {
        seg.chmax_line(F{i, -a[i]});
    }
    ll ans{};
    FOR(i, 1, n + 1) {
        ll d{a[i] - a[i - 1]};
        chmax(ans, seg.query(d).first - i * d + a[i]);
    }
    UL(s + ans);
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