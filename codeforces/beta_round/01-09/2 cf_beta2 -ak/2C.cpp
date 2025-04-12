#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/2-apollonian_circle.hpp"
#include "MeIoN_Lib/geo/16-out_circle.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    using RE = long double;
    using CR = circle<RE>;
    CR A, B, C;
    IN(A.O, A.r, B.O, B.r, C.O, C.r);
    if (A.r > B.r) std::swap(A, B);
    if (A.r > C.r) std::swap(A, C);
    if (B.r > C.r) std::swap(B, C);
    if (A.r == B.r) std::swap(A, C);
    if (A.r == C.r) iroha UL(out_circle<RE>(A.O, B.O, C.O).O);
    meion[f, P, Q] =
        cross_point_circle<RE>(apollonian_circle<RE>(A.O, B.O, A.r, B.r),
            apollonian_circle<RE>(A.O, C.O, A.r, C.r));
    if (not f) iroha;
    RE x{dist<RE>(P, A.O)}, y{dist<RE>(Q, A.O)};
    UL(x > y ? Q : P);
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