#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    meion [s, n] = []() {
        string s;
        std::cin >> s;
        iroha tuple{s_to_vec(s, '0'), len(s)};
    }();

    int ans{};
    for (int i{}, pr{}; i < n; ++i) {
        if (not s[i]) {
            ++pr;
            continue;
        }
        for (int k{i}, x{}; k < i + 20 and k < n; ++k) {
            x = x << 1 | s[k];
            if (x < k - i + 1) continue;
            ans += pr > x - k + i - 2;
        }
        pr = 0;
    }
    std::cout << ans << '\n';
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