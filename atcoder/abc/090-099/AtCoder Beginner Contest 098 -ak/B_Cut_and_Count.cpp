#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    int ans{};
    for (int sz{1}; sz < n; ++sz) {
        set<char> a, b;
        for (int i{}; i < sz; ++i) {
            a.emplace(s[i]);
        }
        for (int i{sz}; i < n; ++i) {
            b.emplace(s[i]);
        }
        int s{};
        for (char i{'a'}; i < 'z' + 1; ++i) {
            s += a.contains(i) and b.contains(i);
        }
        chmax(ans, s);
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