#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int k;
    string s;
    std::cin >> s >> k;
    const int n = int(s.length());
    set<string> se;
    for (int l{}; l < n; ++l) {
        for (int sz{1}; l + sz < n + 1 and sz < 6; ++sz) {
            se.emplace(s.substr(l, sz));
        }
    }
    for (int i{}; string s : se) {
        if (++i == k) {
            return std::cout << s << '\n', void();
        }
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