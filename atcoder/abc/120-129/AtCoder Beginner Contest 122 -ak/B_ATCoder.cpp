#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    for (char &c : s) {
        if (set{'A', 'G', 'C', 'T'}.contains(c)) {
            c = 1;
        } else {
            c = 0;
        }
    }
    const int n = int(s.length());
    int ans{};
    for (int l{}, r{}; l < n; l = r) {
        r = l + 1;
        if (not s[l]) continue;
        while (r < n and s[r]) ++r;
        chmax(ans, r - l);
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