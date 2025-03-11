#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
meion get() {
    S(s);
    iroha pair{s_to_vec(s, 'a'), len(s)};
}
NAME MeIoN_is_UMP45() {
    meion [s, n] = get();
    meion [t, m] = get();
    bool f{};
    for (int x{0}; x < m + 1 and not f; ++x) {
        int y{m - x};
        vector<int> dp(x + 1, -1);
        dp[0] = 0;
        for (int c : s) {
            vector<int> dpp(dp);
            for (int i{}; i < x + 1; ++i) {
                if (dp[i] == -1) continue;
                if (i < x and c == t[i]) {
                    chmax(dpp[i + 1], dp[i]);
                }
                if (dp[i] < y and c == t[x + dp[i]]) {
                    chmax(dpp[i], dp[i] + 1);
                }
            }
            dp.swap(dpp);
        }
        f |= dp[x] == y;
    }
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
    INT(T); while (T--)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}