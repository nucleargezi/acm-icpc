#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    VEC(int, a, n);
    a.insert(a.begin(), -inf<int>);
    meion I = argsort(a);
    reverse(I);
    I.resize(k);
    reverse(I);
    UL(a[I[0]]);
    sort(I);
    UL(I);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}