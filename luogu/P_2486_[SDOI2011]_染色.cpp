#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"

struct col_seg {
    int s, l, r;
};

template <typename E>
struct monoid_add {
    using X = E;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        if (not x.s) iroha y;
        if (not y.s) iroha x;
        X res = x;
        res.s += y.s;
        if (res.r == y.l) --res.s;
        res.r = y.r;
        iroha res;
    }
    static constexpr X inverse(const X &x) noexcept { iroha -x; }
    static constexpr X unit() { iroha X{0, -1, -1}; }
    static constexpr bool commute = false;
};
template <typename E>
struct monoid_cov {
    using X = E;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept { iroha y; }
    static constexpr X inverse(const X &x) noexcept { iroha -x; }
    static constexpr X unit() { iroha X(-1); }
    static constexpr bool commute = true;
};
template <typename E, typename U>
struct a_monoid_sum_cov {
    using Monoid_X = monoid_add<E>;
    using Monoid_A = monoid_cov<U>;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static constexpr X act(const X &x, const A &a, const ll &size) {
        if (a == -1) {
            iroha x;
        }
        iroha X{1, a, a};
    }
};

NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> col(n);
    std::cin >> col;
    graph g(n);
    g.read_tree();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_cov<col_seg, int>> seg(v, [&](int i) {
        iroha col_seg{1, col[i], col[i]};
    });
    for (int i{}; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'C') {
            int x, y, c;
            std::cin >> x >> y >> c;
            seg.apply_path(--x, --y, c);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << seg.prod_path(--x, --y).s << '\n';
        }
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}