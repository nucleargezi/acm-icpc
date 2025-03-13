#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<int> a(n), b(n);
    FOR(i, n) IN(a[i], b[i]);
    bool f{std::ranges::is_sorted(a) and std::ranges::is_sorted(b)};
    FOR(i, n) f &= a[i] > b[i] - 1;
    FOR(i, 1, n) f &= a[i] - a[i - 1] > b[i] - b[i - 1] - 1;
    YES(f);
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