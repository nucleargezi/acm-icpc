#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(string, s, n);
    int ans{};
    FOR(i, 1, n - 1) FOR(k, 1, n - 1) if (s[i][k] == 'X') {
        int f{1};
        for (int x : {-1, 1}) {
            for (int y : {-1, 1}) {
                f &= s[i][k] == s[i + x][k + y];
            }
        }
        ans += f;
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