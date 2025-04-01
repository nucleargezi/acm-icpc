#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(string, a, n);
    int l{inf<int>}, r{-l}, u{l}, d{-l};
    ll have{};
    FOR(i, n) FOR(k, m) if (a[i][k] == 'B') {
        ++have;
        chmin(l, k), chmax(r, k);
        chmin(u, i), chmax(d, i);
    }
    if (l == inf<int>) iroha UL(1);
    ll ans{MAX(r - l, d - u) + 1};
    UL(ans - 1 < MIN(n, m) ? ans * ans - have : -1);
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