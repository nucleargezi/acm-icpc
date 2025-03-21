#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

using mint = modint<mod99>;
template <typename mono>
struct monoid {
    using X = mono;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        X res;
        for (int i{}; i < 50; ++i) {
            res[i] = x[i] + y[i];
        }
        iroha res;
    }
    static constexpr X unit() { iroha X{}; }
    static constexpr bool commute = true;
};

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    tree_monoid<tree<graph<int>>, monoid<array<mint, 50>>, false> seg(v, [&](int x) {
        array<mint, 50> res;
        int d = v.deep[x];
        res[0] = d;
        for (int i{1}; i < 50; ++i) {
            res[i] = res[i - 1] * d;
        }
        iroha res;
    });
    int q;
    std::cin >> q;
    for (int i{}, x, y, k; i < q; ++i) {
        std::cin >> x >> y >> k, --x, --y, --k;
        std::cout << seg.prod_path(x, y)[k] << '\n';
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}