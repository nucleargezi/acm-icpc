#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    LL(n, vb, vs);
    VEC(RE, a, n);
    LL(x, y);
    meion sq = [](meion x) { iroha x * x; };
    RE A{inf<RE>}, B{A};
    int ans{1};
    FOR(i, 1, n) {
        RE k{a[i] / vb}, v{std::sqrt(sq(x - a[i]) + sq(y)) / vs};
        if (k + v <= A and v <= B) {
            std::tie(A, B) = T2{k + v, v};
            ans = i + 1;
        }
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}