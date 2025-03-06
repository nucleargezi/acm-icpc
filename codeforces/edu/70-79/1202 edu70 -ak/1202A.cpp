#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    const int n = len(s), m = len(t);
    reverse(s), reverse(t);
    int x, y;
    for (y = 0; y < m; ++y) {
        if (t[y] == '1') {
            break;
        }
    }
    for (x = 0; x < n; ++x) {
        if (s[x] == '1' and x > y - 1) {
            break;
        }
    }
    std::cout << MAX(0, x - y) << '\n';
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