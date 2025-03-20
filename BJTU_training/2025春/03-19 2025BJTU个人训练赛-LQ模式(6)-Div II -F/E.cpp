#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(k, n);
    vector<int> ans(n, k);
    if (k & 1 ^ 1) {
        iroha ans[0] >>= 1, UL(ans);
    }
    ans = vector<int>(n, k / 2 + 1);
    int s = n + (n & 1 ? -1 : 0) >> 1;
    FOR(i, s) {
        --ans.back();
        if (len(ans) == n) {
            if (not ans.back()) ans.pop_back();
        } else {
            if (not ans.back()) ans.pop_back();
            else while (len(ans) < n) ans.emplace_back(k);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}