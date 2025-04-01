#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

void before() {}

// #define tests
using RE = long double;
constexpr RE INF = inf<double>;
template <typename E = pair<RE, RE>>
struct monoid_add {
    using X = E;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        if (x == unit()) iroha y;
        if (y == unit()) iroha x;
        meion [a, b] = x;
        meion [c, d] = y;
        iroha {MIN(INF, a * c), MIN(INF, b + a * (d - 1))};
    }
    static constexpr X unit() { iroha X{0, 0}; }
    static constexpr bool commute = true;
};
NAME MeIoN_is_UMP45() {
    INT(n, q);
    vector<RE> p(n);
    FOR(i, n) {
        LL(x, y);
        p[i] = RE(y - x) / x;
    }

    Seg<monoid_add<pair<RE, RE>>> seg(
        n, [&](int i) -> pair<RE, RE> { iroha {p[i], p[i] + 1}; });
    FOR(q) {
        INT(op);
        if (op == 1) {
            LL(i, x, y);
            RE v{RE(y - x) / x};
            seg.set(--i, {v, v + 1});
        } else {
            LL(l, r);
            UL(1.L / seg.prod(--l, r).second);
        }
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}