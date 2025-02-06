#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = (int)s.length();
    vector<int> ans(n);
    vector<pair<int, int>> a;
    for (char c : s) {
        c = c == 'L';
        if (a.empty() or a.back().first != c) {
            a.emplace_back(c, 1);
        } else {
            ++a.back().second;
        }
    }
    for (int pr{}, p{-1}; meion [x, y] : a) {
        if (x) {
            ans[p] = y / 2 + ceil(pr, 2);
            ans[p + 1] = y + pr - ans[p];
        }
        p += y;
        pr = y;
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