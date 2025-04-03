#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    UL(n * (n + 1) / 2 & 1);
    ll s{n * (n + 1) >> 2};
    vector<int> ans;
    while (s) {
        ll cut{MIN(s, n--)};
        s -= cut;
        ans.emplace_back(cut);
    }
    reverse(ans);
    UL(len(ans), ans);
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