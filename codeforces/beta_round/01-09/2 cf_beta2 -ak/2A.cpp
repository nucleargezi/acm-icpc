#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    using P = pair<string, int>;
    VEC(P, a, n);
    map<string, int> M;
    for (meion [x, y] : a) M[x] += y;
    int mx{-inf<int>};
    for (meion [x, y] : M) {
        chmax(mx, y);
    }
    map<string, int> MM;
    for (meion [x, y] : a) {
        if ((MM[x] += y) > mx - 1 and M[x] == mx) iroha UL(x);
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}