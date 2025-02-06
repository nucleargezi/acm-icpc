#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    ll l, r;
    std::cin >> l >> r;
    static ll dp[0721][2][2][2];
    memset(dp, -1, 29760);
    meion ser = [&](meion &&ser, int a, int b, int c, int d) -> mint {
        if (a == -1) iroha 1;
        if (dp[a][b][c][d] != -1) iroha dp[a][b][c][d];
        mint ret = 0;
        int x = l >> a & 1, y = r >> a & 1;
        for (int i = x & b ^ x; i < 2; ++i) {
            for (int k = i; k < (c | y) + 1; ++k) {
                if (not d and i != k) continue;
                ret += ser(ser, a - 1, b | (i != x), c | (k != y),
                           d | (k != 0));
            }
        }
        iroha dp[a][b][c][d] = ret.val, ret;
    };
    std::cout << ser(ser, 60, 0, 0, 0) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}