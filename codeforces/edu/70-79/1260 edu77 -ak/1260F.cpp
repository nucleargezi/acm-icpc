#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/ds/monoid/add_array.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
template <typename T>
struct mono {
    using Monoid_X = monoid_add_array<T, 3>;
    using Monoid_A = monoid_add<T>;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(const X &x, const A &tag, const ll &size) {
        meion [a, b, c] = x;
        iroha {a, b + a * tag, c + (tag + tag) * b + tag * tag * a};
    }
};
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> L(n), R(n);
    mint mul{1};
    constexpr int N = 1'00'001;
    static vector<pair<int, mint>> add[N];
    for (int i{}; i < n; ++i) {
        std::cin >> L[i] >> R[i];
        --L[i];
        mul *= R[i] - L[i];
        add[L[i]].emplace_back(i, inv<mint>(R[i] - L[i]));
        add[R[i]].emplace_back(i, -inv<mint>(R[i] - L[i]));
    }
    graph g(n);
    g.read_tree();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, mono<mint>> seg(
        v, [](int i) { iroha array<mint, 3> {1, 0, 0}; });
    mint ans, x, y;
    for (int i{}; i < N; ++i) {
        for (meion [id, inv] : add[i]) {
            x += inv;
            y += inv * v.deep[id];
            seg.apply_path(0, id, inv);
        }
        ans += x * x + x * y - std::get<2>(seg.prod_all());
    }
    ans *= mul;
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