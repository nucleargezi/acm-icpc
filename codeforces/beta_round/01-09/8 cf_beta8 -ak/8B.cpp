#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    int x{}, y{};
    map<array<int, 2>, int> M;
    ++M[{x, y}];
    bool f{true};
    constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    for (char c : s) {
        x += c == 'R' ? 1 : c == 'L' ? -1 : 0;
        y += c == 'U' ? 1 : c == 'D' ? -1 : 0;
        ++M[{x, y}];
        int s{};
        FOR(d, 4) {
            int xx{x + dx[d]}, yy{y + dy[d]};
            s += M.contains({xx, yy});
        }
        f &= s < 2;
    }
    for (meion [x, y] : M) f &= y < 2;
    UL(f ? "OK" : "BUG");
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