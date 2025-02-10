#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mat.hpp"

void before() {}

#define tests

using mint = modint<mod99>;
using mat = MAT<mint, 5>;
struct monoid {
    using X = mat;
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept { iroha x * y; }
    static constexpr X unit() { iroha X(1); }
    static constexpr bool commute = false;
};
constexpr array<array<mint, 5>, 5> x {array<mint, 5> {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {1, 0, 2, 0, 1}, {1, 1, 0, 2, 1}, {0, 0, 0, 0, 1}},
                                   y {array<mint, 5> {2, 0, 1, 0, 1}, {0, 2, 1, 1, 1}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}};
NAME MeIoN_is_UMP45() {
    meion [n, s] = []() {
        string s;
        std::cin >> s;
        iroha pair{(int)s.length(), s_to_vec(s, '0')};
    }();
    meion reset = [&](int i) -> mat { iroha(s[i] ? x : y); };
    Seg<monoid> seg(n, reset);
    int q;
    std::cin >> q;
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        s[--x] ^= 1;
        seg.set(x, reset(x));
        meion res = seg.prod_all();
        std::cout << (res[1][4] + res[3][4]).val << " \n"[i + 1 == q];
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