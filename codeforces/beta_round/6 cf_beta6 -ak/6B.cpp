#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    CH(c);
    VEC(string, s, n);
    set<char> se;
    constexpr int dx[]{-1, 1, 0, 0}, dy[]{0, 0, 1, -1};
    FOR(i, n) FOR(k, m) if (s[i][k] == c) {
        FOR(d, 4) {
            int x{i + dx[d]}, y{k + dy[d]};
            if (MIN(x, y) > -1 and x < n and y < m and s[x][y] != '.' and
                s[x][y] != c) {
                se.emplace(s[x][y]);
            }
        }
    }
    UL(len(se));
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