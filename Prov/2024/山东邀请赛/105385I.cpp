#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    int n(len(s));

    int ans{s[0] == s[--n] ? 0 : inf<int>};
    FOR(i, n) if (s[i] == s[i + 1]) {
        chmin(ans, ++i);
        break;
    }
    UL(ans == inf<int> ? -1 : ans);
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