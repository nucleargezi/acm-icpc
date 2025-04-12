#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    constexpr int n{8};
    VVEC(char, a, n, n);
    int x{}, y{};
    FOR(i, n) {
        int f{1}, t{1};
        FOR(k, n) f &= a[i][k] == 'B', t &= a[k][i] == 'B';
        x += f, y += t;
    }
    if (x == y and x == n) iroha UL(n);
    else UL(x + y);
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