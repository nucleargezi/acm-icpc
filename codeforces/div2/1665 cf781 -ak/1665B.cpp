#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);

    map<int, int> M;
    FOR(i, n) ++M[a[i]];
    int mx{};
    for (meion [x, y] : M) chmax(mx, y);
    
    int x{}, t{ceil(n, mx)};
    while ((1 << x) < t) ++x;
    UL(x + n - mx);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}