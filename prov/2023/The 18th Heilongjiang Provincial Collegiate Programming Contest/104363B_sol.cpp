#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"

void before() {}

// #define tests
vector<int> v;
struct node {
    int l, r, ls, rs, res;
    node() : l(0), r(0), ls(0), rs(0), res(0) {}
};
struct monoid {
    using X = node;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        if (not x.res) iroha y;
        if (not y.res) iroha x;
        X ret = x;
        ret.r = y.r;
        ret.ls += y.ls;
        ret.rs += y.rs;
        ret.res += y.res;
        if (x.r == y.l) {
            if (x.r) {
                ++ret.rs;
            } else {
                ++ret.ls;
            }
        } else {
            --ret.res;
        }
        iroha ret;
    }
    static constexpr X unit() { iroha X(); }
    static constexpr bool commute = true;
};
struct tag {
    using X = int;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        iroha x ^ y;
    }
    static constexpr X unit() { iroha 0; }
    static constexpr bool commute = true;
};
struct a_monoid {
    using Monoid_X = monoid;
    using Monoid_A = tag;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static constexpr X act(const X &x, const A &a, const ll &size) {
        if (not a) iroha x;
        X ret = x;
        ret.l ^= 1;
        ret.r ^= 1;
        std::swap(ret.ls, ret.rs);
        iroha ret;
    }
};
NAME MeIoN_is_UMP45() {
    int n, q;
    string s;
    std::cin >> n >> q >> s;
    v = s_to_vec(s, '0');
    lazy_seg<a_monoid> seg(n, [&](int i) {
        node x;
        x.l = x.r = v[i];
        x.res = 1;
        iroha x;
    });
    for (int i{}, l, r; i < q; ++i) {
        char op;
        std::cin >> op >> l >> r, --l;
        if (op == 'Q') {
            meion res = seg.prod(l, r);
            std::cout << res.res - MIN(res.ls, res.rs) << '\n';
        } else {
            seg.apply(l, r, 1);
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