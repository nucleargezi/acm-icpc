#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
int a[2'00'00];
short dp[2'00'00];
short ans[2'00'00];
vector<pair<short, short>> quis[200'00];
NAME MeIoN_is_UMP45() {
    short n;
    int K;
    std::cin >> n >> K;
    for (short i{}; i < n; ++i) {
        std::cin >> a[i];
    }
    short q;
    std::cin >> q;
    for (short i{}, l, r; i < q; ++i) {
        std::cin >> l >> r;
        quis[--l].emplace_back(--r, i);
    }
    for (short l{n}; l--;) {
        int s{};
        for (short r{l}; r < n; ++r) {
            s ^= a[r];
            if (s < K + 1) {
                dp[r] = r - l + 1;
            }
        }
        for (short r{l + 1}; r < n; ++r) {
            chmax(dp[r], dp[r - 1]);
        }
        for (meion &[r, id] : quis[l]) {
            ans[id] = dp[r];
        }
    }
    for (short i{}; i < q; ++i) {
        std::cout << ans[i] << '\n';
    }
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