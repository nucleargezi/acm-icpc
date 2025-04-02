#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion FL = []() { std::cout.flush(); };
    meion quis = [&](const string &q) -> int {
        UL(q);
        FL();
        INT(dis);
        if (not dis) exit(0);
        iroha dis;
    };
    int a{quis(string(300, 'a'))}, b{quis(string(300, 'b'))};
    a = 300 - a, b = 300 - b;
    int n{a + b};
    string s(n, 'a'), ans{s};
    FOR(i, n - 1) {
        s[i] = 'b';
        int dis{quis(s)};
        s[i] = 'a';
        ans[i] = dis == b - 1 ? 'b' : 'a';
    }
    if (std::ranges::count(ans, 'a') != a) ans.back() = 'b';
    quis(ans);
}
// abab
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