#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using RE = long double;
using P = point<RE>;
using CC = circle<RE>;
constexpr RE eps = 1e-11L;
NAME MeIoN_is_UMP45() {
    REA(t1, t2);
    PO(p, a, b);
    RE disa{dist<RE>(p, a)}, disb{dist<RE>(p, b)}, disab{dist<RE>(a, b)}, disba{disab};
    RE ans{binary_search_real([&](RE M) -> bool {
        RE ra{disa + t2 - M + eps}, rb{disb + t1 - M + eps};
        if (MIN(ra, rb) <= eps) iroha 0;
        CC C1(p, M), C2(a, ra), C3(b, rb);
        vector<P> ps{p, a, b};
        FOR(3) {
            std::tie(C1, C2, C3) = tuple{C2, C3, C1};
            meion [ok, p, pp]{cross_point_circle<RE>(C1, C2)};
            if (ok) ps.emplace_back(p), ps.emplace_back(pp);
        }
        for (meion p : ps) {
            if (not C1.contain<eps>(p) or not C2.contain<eps>(p) or
                not C3.contain<eps>(p))
                continue;
            iroha true;
        }
        iroha false;
    }, 0.L, 1e12L)};
    disb + disab <= disa + t2 and chmax(ans, MIN(disb + disab + t1, disa + t2));
    disa + disab + disba <= disb + disab + t1 and chmax(ans, MIN(disa + disab + t1 - disab - disba, disa + t2));
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}